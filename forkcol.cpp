
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main(){
	int n=0;
	int k=0;
	
	pid_t islem;

		do
		{
			printf("Collatz icin 0'dan buyuk bir rakam giriniz.'\n"); 
  			scanf("%d", &k);	
		}while (k <= 0);

		islem = fork();

		if (islem == 0)
		{
			printf("Child calisiyor.\n");
			printf("%d\n",k);
			while (k!=1)
			{
				if (k%2 == 0)
				{
					k = k/2;
				}
				else if (k%2 == 1)
				{
					k = 3 * (k) + 1;
				}	
			
				printf("%d\n",k);
			}
		
			printf("Child islem tamam\n");
		}
		else
		{
			printf("Parents child islemi bekliyor\n");
			wait();
			printf("Parent islem tamamlandi.\n");
		}
	return 0; 
}
