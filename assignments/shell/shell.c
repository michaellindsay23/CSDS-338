#include <stddef.h>
#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

// Manage Jobs
struct Job {
  int pid;
  char* name;
};

struct Job* job_list;
int job_list_size = 0;
int job_list_max_size = 32;

void addJob(int pid, char* name) {
  struct Job new_job = { .pid = pid, .name = name };
  job_list[job_list_size] = new_job; 
  job_list_size++;
}

void remove_job(int pid) {
  struct Job* new_list = malloc(job_list_max_size * sizeof(struct Job));
  for (int i = 0; i < job_list_max_size; i++) {
    struct Job temp = { .pid = 0, .name = NULL };
    new_list[i] = temp;
  }

  int pos = 0;
  int has_skipped = 0;
  struct Job* current_job = &job_list[pos];
  while (current_job->name != NULL) {
    if (current_job->pid != pid) {
      new_list[pos - has_skipped] = *current_job;
    } else {
      has_skipped++;
    }

    pos++;
    current_job = &job_list[pos];
  }

  free(new_list);
  
  job_list = new_list;

  job_list_size--;
}

// Utility
void clean(char* buffer) {
  while (*buffer != '\n') {
    buffer++;
  }
  *buffer = '\0';
}

char** split_line(char* line, int buffersize) {
  char** tokens = malloc(sizeof(char*) * buffersize);
  char* token = strtok(line, " ");
  int position = 0;

  while(token != NULL) {
    tokens[position] = token;
    position++;
    token = strtok(NULL, " ");
  }

  tokens[position] = NULL;

  return tokens;
}

// Execution
void execute(char** args) {  
  char* const env[] = {NULL};

  int pid = fork();

  if (pid == 0) {
    execve(args[0], args, env);
  } else {
    addJob(pid, args[0]);
    waitpid(pid, NULL, WUNTRACED);
    remove_job(pid);
  }
}

void* execute_background(void* arg) {
  char** args = arg;
  execute(args);
  free(args);
  return NULL;
}

// Main loop
int main() {
  job_list = malloc(job_list_max_size * sizeof(struct Job));
  for (int i = 0; i < job_list_max_size; i++) {
    struct Job temp = { .pid = 0, .name = NULL };
    job_list[i] = temp;
  }

  pthread_t thread_list[32];
  int num_threads = 0;

  int buffersize = 64;
  char buffer[buffersize];
  char** args;

  while (1) {
    printf("fih ~ ");
    char* buf = fgets(buffer, buffersize, stdin);
    clean(buffer);

    args = split_line(buffer, buffersize);

    if (strcmp(args[0], "exit") == 0) {
      break;
    }

    if (strcmp(args[0], "jobs") == 0) {
      if (job_list[0].name == NULL) {
        continue;
      }

      printf("PID\t\tProgram\n");

      int pos = 0;
      struct Job current_job = job_list[pos];
      while (current_job.name != NULL) {
        printf("%i\t\t%s\n", current_job.pid, current_job.name);

        pos++;
        current_job = job_list[pos];
      }

      continue;  
    } 

    // Check if last character is &
    int i = 0;
    while (args[i+1] != NULL) {
      i++;
    }

    if (*args[i] == '&') {
      pthread_t thread;
      thread_list[num_threads] = thread;
      num_threads++;

      pthread_create(&thread_list[num_threads], NULL, execute_background, args);
    } else {
      execute(args);
    }
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_join(thread_list[i], NULL);
  }

  free(args);
  free(job_list);

  return 0;
}
