//CODE FOR READING 'C' TYPE DECLARATIONS.
#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[]){
	int i = 0, j = 0, pstatus = 0;
	for(j = 0; j < strlen(argv[2]); j++){
		if(argv[2][j] == '('){							//DETECT FUNCTION.
			printf(" is function taking ");
			if(argv[2][j+1] == ')'){
				printf(" no arguments and returning");
				break;
			}
			i = 2;
			while(argv[i][j] != ')'){					//WRITE FUNCTION ARGUMENTS.
				printf("%c", argv[i][j]);
				j++;
				if(j == strlen(argv[i])){
					i++;
					j = 0; 
				}
			}
			printf(") arguments and returning");
			break;
		}
		else if(argv[2][j] == '['){						//DETECT ARRAY.
			if(argv[2][j+1] == ']') printf(" is an array of");
			else printf(" is an array of 10");
			break;
		}
		else if(argv[2][j] == ';') printf(" is");		//DETECT END OF STATEMENT.
		else if(argv[2][j] == '*'){						//DETECT POINTER.
			i = pstatus = 1;
			while(argv[2][i] != '[' && argv[2][i] != '(' && argv[2][i] != ';'){
				printf("%c", argv[2][i]);
				i++;
			}
		}
		else if(pstatus == 0) printf("%c", argv[2][j]);
	}
	printf((argv[2][0] == '*') ? " pointer(s) to %s." : " %s.", argv[1]);
	return 0;
}
