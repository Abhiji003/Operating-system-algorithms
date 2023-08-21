#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>

struct student {
    char name[20];
    int rank;
};

int main() {
    int i, n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student *s;
    int shmid = shmget(IPC_PRIVATE, n * sizeof(struct student), 0777|IPC_CREAT);
    s = (struct student *) shmat(shmid, 0, 0);
    for(i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", (s+i)->name);
        printf("Enter the rank of student %d: ", i+1);
        scanf("%d", &(s+i)->rank);
    }
    pid_t pid = fork();
    if(pid == 0) {
        printf("\nRank details of students:\n");
        for(i = 0; i < n; i++) {
            printf("Name: %s\n", (s+i)->name);
            printf("Rank: %d\n", (s+i)->rank);
        }
        exit(0);
    }
    else {
        wait(NULL);
        shmdt(s);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}