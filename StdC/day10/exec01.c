#include <stdio.h>
//typedef struct{
typedef struct student{
	int	id;
	char	*name;
	char	*birthday;
	} STU;
typedef struct student2{
	int	id;
	char	name[10];
	char	birthday[10];
	} STU2;
void print_stu(STU *stu){
	printf("%d %s %s\n", stu->id, stu->name, stu->birthday);
}
void print_stu2(STU2 *stu){
	printf("%d %s %s\n", stu->id, stu->name, stu->birthday);
}
int main(){
	struct student stu = {2, "jjj", "2018"};
	printf("%d %s %s\n", stu.id, stu.name, stu.birthday);

	STU stu1 = {3, "aaa", "2019"};
	printf("%d %s %s\n", stu1.id, stu1.name, stu1.birthday);

	STU stu2;
	stu2.id 	= 4;
	stu2.name 	= "bbb";
	stu2.birthday 	= "2010";
	print_stu(&stu2);

	STU2 stu3	={0, "ddd", "2003"};
	//STU2 stu3;
	stu3.id		= 5;
	//stu3.name	= "ddd";
	//stu3.birthday	= "2003";
	print_stu2(&stu3);

	//STU stu4;
	STU2 stu4;
	scanf("%d%s%s", &stu4.id, stu4.name, stu4.birthday);
	//fgets(stu4.name, 10, stdin);
	//if(strlen(stu4.name) == 9 && stu4.name[8] != '\n'){
	//	scanf("%*[^\n]");
	//	scanf("%*c");
	//	}
	//print_stu(&stu4);
	print_stu2(&stu4);
	
	STU stu5;
	stu5 = stu;
	print_stu(&stu5);

	STU2 stu6;
	stu6 = stu3;
	print_stu2(&stu6);
}
