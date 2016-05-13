#include<stdio.h>
#define N 30

void init_array();
void insert();
void flags_number();
int select(int num);
void change_int();
void sum_int();
void init_second();
void init_number();
void sum_add();

int number[N],flags[N],zero[N],new_int[N],stack_int[N],stack[N];

char str[N];
int jk;
int bbc;
int s;
int global_x = 8; //グローバル変数。入力時に変数x(小文字)を使用する 

FILE *fp;
int main(){
	fp = fopen("test.log","w");

	   if(!fp){
		printf("don`t make file\n");
		return -1;
	}

	int n;
	 init_array();

	 insert();
	 flags_number();
	change_int();

	for(n=0;n<20;n++)
		fprintf(fp,"stack_int[%d]=%d\n",n,stack_int[n]);
	sum_int();
	sum_add();

	fclose(fp);
	printf("--END--\n");
return 0;
}


void init_array(){
	int i,j=1;
	for(i=0;i<N;i++){
	number[i]=0; flags[i]=0; str[i]=0,zero[i]=0, stack[N]=0;
	new_int[i]=-1; stack_int[i]=-10;
	}

	i = 1;
	for(j=0;j<10;j++){
				
		zero[j]=i;
		i=(i*10);
	}	

}
	void insert(){
	printf("calc number-->"); scanf("%s",str);

	printf("\n");
}

void flags_number(){
	int i=0,j=0,k,num;
	while(str[i]){
		num =str[i];
		k=select(num);  //1-9までか、
		number[i]=k;
i++;}

	/*for(j=0;j<N;j++){
		printf("number[%d]=%d\n",j,number[j]);
		printf("flags[%d]=%d\n",j,flags[j]);
	}*/

		for(i=0;i<10;i++)
		fprintf(fp,"zero[%d]=%d\n",i,zero[i]);

}

int select(int number){
		if(number == 0) return -1;
			int k=48;
		number=(number%48);
		if(number==43){
			flags[jk]=43;
		}else if(number==45){
			flags[jk]=45;
		}else if(number == 42){
			flags[jk]=42;
		}else if(number==47){
			flags[jk]=47;
		}else if(number == 24){
			flags[jk]=24;
		}else{
			flags[jk]=1;
		}
		
	jk++;
	return number;
}

void change_int(){ //int型に変換する
	fprintf(fp,"check\n");
	int i=0,j=0,k=0,num=0,n=0,c=0,flag_pointer=0;
	
	while(flags[flag_pointer]!=0){
			c++;
		flag_pointer++;}
			 bbc=(c--);
	while(flags[c]!=0){  // 0単独の加減乗除は判定しない(今は）
		if(number[c]<40 && number[c]!=24){
		stack_int[j++] = number[c]*zero[k];
		k++; fprintf(fp,"%d---\n",k);
		}else if(number[c]==43){
			stack_int[j++]=-1; k=0;
		}else if(number[c]==45){
			stack_int[j++]=-2; k=0;
		}else if(number[c]==47){
			stack_int[j++]=-3; k=0;
		} else if(number[c]==42){
			stack_int[j++]=-4;
			 k=0;}else if(number[c]==24){
			stack_int[j++]=-5; k=0;
			}
	c--;  }   //cを添字に使う
		fprintf(fp,"bbc====%d\n",bbc);
}

void sum_int(){
	init_second();
}

void init_second(){
	int i,q=0,num=0,a=0;
	s=0;  //グローバル変数

	for(i=0;i<N;i++){
		flags[i]=0;  //flags[]に格納
	}
		i=(bbc-1);  //配列の添字
		int jkl=0;
		while(i>=0){
			while(stack_int[i] > -1){
				a++;
			num+=stack_int[i]; i--; if(i==-1) break;
			}//	i-=a;
				flags[s]=num;
				//i-=a;
				//flags[i]=num;
			 if(stack_int[i] == -1){
			flags[++s]=-1;s++; i--;
			/*flags[s++]=num;*/ num=0;
			}else if(stack_int[i] == -2){
			flags[++s]=-2;s++; i--;
			/*flags[s++]=num;*/ num=0;
			}else if(stack_int[i] == -3){
			flags[++s]=-3;s++; i--;
			/*flags[s++]=num;*/ num=0;
			}else if(stack_int[i] == -4){
			flags[++s]=-4;s++; i--;
			/*flags[s++]=num;*/ num=0;
			}else if(stack_int[i] == -5){
			flags[s]=global_x; s++; i--;
			}
	//	if(i==0){q+=stack_int[0]; num+=q; flags[0]=num;}
	 }
		//flags[s]=num;


	for(i=0;i<20;i++){
		fprintf(fp,"flags[%d]=%3d\n",i,flags[i]);
	}
}


void init_number(){

	int k=0;

	for(k=0;k<N;k++){
		number[k]=0;
	}
}

void sum_add(){   //number配列で添字はグローバル変数s
	int i,j=0,k,sum=0;
	fprintf(fp,"s ====%d\n",s);

	for(i=0;i<=s;i++){
		if(flags[i]>=0){
			sum+=flags[i];
		}

		if(flags[i]==-2){
			sum-=flags[++i];
		}else if(flags[i] == -4){
			sum*=flags[++i];
		}else if(flags[i] == -1){
			sum+=flags[++i];
		}else if(flags[i] == -3){
			sum/=flags[++i];
		}
	}

	printf("sum ==%3d\n",sum);
}
