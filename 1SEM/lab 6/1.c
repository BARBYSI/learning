#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
void ctos(char *s,int a,char *ch)     
{
	ch[0]=s[a];
	ch[1]='\0';
}
int main(){
	char str1[80], ss[80]=" ", ch[2];
	int ks = 0;
	int length, j, i = 0;
	printf("input the phrase:\n");
	gets(str1);

	strcat(ss,str1);     //чтоб добавить пробел в начале строки  
						//важно для нахождения начала 1го слова
	length = strlen(ss);
	strcpy(str1,"");              //обнуляем ss1

	while(i < length)
	{
		if ((ss[i]==' ') && (ss[i + 1]!=' '))
		{
		i++;
		while((ss[i + ks] != ' ') && ((i + ks) < length))
		ks++;
		
		if ((! (ks % 2)) && (ks != 0)) 
			for(j = i;j <= (i + ks); j++)
			{
				ctos(ss,j,ch);
				strcat(str1,ch);
			}
			i = i + ks - 1;
			ks=0;
		}
	i++;
	}
	printf("\nrezultat\n");
	printf("%s",str1);
	getch();
}