#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int grade_credit(char ch[]);

typedef struct student_records {
	char *student_name;
	char mis_num[13];
	char *grades[6];
	float sgpa;
	int subject_credits[6];
} student_record;	

enum grade_point {DD = 4, CD, CC, BC, BB, AB, AA};

enum credits {UVC = 3, SPE = 3, BEE = 3, EM = 3, CAED = 3, PC = 1};

int main() {
	int class_strength, i, j = 0, k, count, l, option, count_1;
	char temp[9], temp_mis_num[13], temp_subject[4], c;
	char *grade_type[] = {"AA", "AB", "BB", "BC", "CC", "CD", "DD"}; 
	printf("Enter class strength: ");
	scanf("%d", &class_strength);
	scanf("%c", &c);
	student_record record[class_strength], temp_record;
	for(i = 0; i < class_strength; i++) {
		printf("Enter student name: ");
		record[i].student_name = (char *)malloc(sizeof(char) * 50);
		fgets(record[i].student_name, 50, stdin);
		*(record[i].student_name + strlen(record[i].student_name) - 1) = '\0';
		printf("Enter MIS No: ");
		scanf("%s", record[i].mis_num);
		for(k = 0; k < 8; k++) {
			temp[k] = record[i].mis_num[k];
		}
		temp[8] = '\0';
		while(strcmp(temp, "MIS11160")) {
			printf("Enter valid MIS No: ");
			scanf("%s", record[i].mis_num);
			for(k = 0; k < 8; k++) {
				temp[k] = record[i].mis_num[k];
			}
		}
		for(k = 0; k < 6; k++) {
			switch(k) {
				case 0:
					printf("Enter UVC grade: ");
					record[i].grades[k] = (char *)malloc(sizeof(char) * 2);
					LABEL: scanf("%s", record[i].grades[k]);
					count = 0;
					for(l = 0; l < 7; l++) {
						if(!strcmp(record[i].grades[k], grade_type[l])) {
							count++;
						}
					}
					if(!count) {
						printf("Enter valid UVC grade: ");
						goto LABEL;
					}
					else if(count) {
						record[i].subject_credits[k] = grade_credit(record[i].grades[k]);
					}
					break;
				case 1:
					printf("Enter SPE grade: ");
					record[i].grades[k] = (char *)malloc(sizeof(char) * 2);
					LABEL_1: scanf("%s", record[i].grades[k]);
					count = 0;
					for(l = 0; l < 7; l++) {
						if(!strcmp(record[i].grades[k], grade_type[l])) {
							count++;
						}
					}
					if(!count) {
						printf("Enter valid SPE grade: ");
						goto LABEL_1;
					}
					else if(count) {
						record[i].subject_credits[k] = grade_credit(record[i].grades[k]);
					}
					break;
				case 2:
					printf("Enter BEE grade: ");
					record[i].grades[k] = (char *)malloc(sizeof(char) * 2);
                                	LABEL_2: scanf("%s", record[i].grades[k]);
                                	count = 0;
                                	for(l = 0; l < 7; l++) {
                                        	if(!strcmp(record[i].grades[k], grade_type[l])) {
                                                	count++;
                                        	}	
                                	}	
                                	if(!count) {
                                        	printf("Enter valid BEE grade: ");
                                        	goto LABEL_2;
                                	}
                                	else if(count) {
                                        	record[i].subject_credits[k] = grade_credit(record[i].grades[k]);
                                	}
					break;	
				case 3:
					printf("Enter EM grade: ");
					record[i].grades[k] = (char *)malloc(sizeof(char) * 2);
                                	LABEL_3: scanf("%s", record[i].grades[k]);
                                	count = 0;
                                	for(l = 0; l < 7; l++) {
                                        	if(!strcmp(record[i].grades[k], grade_type[l])) {
                                                	count++;
                                        	}
                                	}
                                	if(!count) {
                                        	printf("Enter valid EM grade: ");
                                        	goto LABEL_3;
                                	}
                                	else if(count) {
                                        	record[i].subject_credits[k] = grade_credit(record[i].grades[k]);
                                	}
					break;
				case 4:
					printf("Enter CAED grade: ");
					record[i].grades[k] = (char *)malloc(sizeof(char) * 2);
                                	LABEL_4: scanf("%s", record[i].grades[k]);
                                	count = 0;
                                	for(l = 0; l < 7; l++) {
                                        	if(!strcmp(record[i].grades[k], grade_type[l])) {
                                        	        count++;
                                        	}
                                	}
                                	if(!count) {
                                        	printf("Enter valid CAED grade: ");
                                        	goto LABEL_4;
                                	}
                                	else if(count) {
                                        	record[i].subject_credits[k] = grade_credit(record[i].grades[k]);
                                	}
					break;
				case 5:
					printf("Enter PC grade: ");
					record[i].grades[k] = (char *)malloc(sizeof(char) * 2);
                                	LABEL_5: scanf("%s", record[i].grades[k]);
                                	count = 0;
                                	for(l = 0; l < 7; l++) {
                                        	if(!strcmp(record[i].grades[k], grade_type[l])) {
                                                	count++;
                                        	}
                                	}
                                	if(!count) {
                                        	printf("Enter valid PC grade: ");
                                        	goto LABEL_5;
                                	}
                                	if(count) {
                                        	record[i].subject_credits[k] = grade_credit(record[i].grades[k]);
                                	}
					break;
			}
			scanf("%c", &c);
		}
		record[i].sgpa = (record[i].subject_credits[0] * UVC + record[i].subject_credits[1] * SPE + record[i].subject_credits[2] * BEE + record[i].subject_credits[3] * EM + record[i].subject_credits[4] + CAED + record[i].subject_credits[5] * PC) / 16.0;
	}
	for(i = 0; i < class_strength; i++) {
		for(j = i + 1; j < class_strength; j++) {
			if(strcmp(record[i].mis_num, record[j].mis_num) > 0) {
				temp_record = record[j];
				record[j] = record[i];
				record[i] = temp_record;
			}
		}
	}
	for(i = 0; i < class_strength; i++) {
		printf("%s\n", record[i].mis_num);
	}
	LABEL_6: printf("1. View student marklist. Enter 1.\n");
	printf("2. View entire class result. Enter 2.\n");
	printf("3. View entire class result according to subject. Enter 3.\n");
	printf("4. Enter -1 as option to exit.\n");
	printf("Enter preferred option: ");
	LABEL_7: scanf("%d", &option);
	if(option == 1) {
		LABEL_8: printf("Enter MIS No. of student: ");
               	scanf("%s", temp_mis_num);
		count_1 = 0;
               	for(i = 0; i < class_strength; i++) {
               		if(!strcmp(temp_mis_num, record[i].mis_num)) {
				count_1++;
                       		printf("Student name: %s\n", record[i].student_name);
                       		printf("UVC grade: %s\n", record[i].grades[0]);
                       		printf("SPE grade: %s\n", record[i].grades[1]);
                       		printf("BEE grade: %s\n", record[i].grades[2]);
				printf("EM grade: %s\n", record[i].grades[3]);
				printf("CAED grade: %s\n", record[i].grades[4]);
				printf("PC grade: %s\n", record[i].grades[5]);
				printf("SGPA: %f\n", record[i].sgpa);
				break;
			}
		}
		if(!count_1) {
			printf("MIS No. not found in records.\n");
			printf("Enter MIS No. again.\n");
			goto LABEL_8;
		}
		goto LABEL_6;				
	}
	else if(option == 2) {
		printf("MIS No. \t\tStudent Name  \t\t\t\t\t\t\t\t\tUVC  SPE  BEE  EM  CAED  PC  SGPA\n");
		for(i = 0; i < class_strength; i++) {
			printf("%s\t%s", record[i].mis_num, record[i].student_name);
			for(j = 0; j < 48 - strlen(record[i].student_name); j++) {
				printf(" ");
			}
			printf("%s   %s   %s   %s  %s    %s  %.2f\n", record[i].grades[0], record[i].grades[1], record[i].grades[2], record[i].grades[3], record[i].grades[4], record[i].grades[5], record[i].sgpa);
		}
		goto LABEL_6;
	}
	else if(option == 3) {
		printf("(Enter UVC/SPE/BEE/EM/CAED/PC in this specified format only)\n");
		LABEL_9: printf("Enter Subject: ");
		scanf("%s", temp_subject);
		if(!strcmp(temp_subject, "UVC")) {
			printf("MIS No. \t\tStudent Name  \t\t\t\t\t\t\t\t\tUVC\n");
			for(i = 0; i < class_strength; i++) {
				printf("%s\t%s", record[i].mis_num, record[i].student_name);
				for(j = 0; j < 48 - strlen(record[i].student_name); j++) {
                                printf(" ");
                        	}
				printf("%s\n", record[i].grades[0]);
			}
		}
		else if(!strcmp(temp_subject, "SPE")) {
			printf("MIS No. \t\tStudent Name  \t\t\t\t\t\t\t\t\tSPE\n");
			for(i = 0; i < class_strength; i++) {
                                printf("%s\t%s", record[i].mis_num, record[i].student_name);
				for(j = 0; j < 48 - strlen(record[i].student_name); j++) {
                                printf(" ");
                        	}
				printf("%s\n", record[i].grades[1]);
	                }
		}
		else if(!strcmp(temp_subject, "BEE")) {
			printf("MIS No. \t\tStudent Name  \t\t\t\t\t\t\t\t\tBEE\n");
                        for(i = 0; i < class_strength; i++) {
                                printf("%s\t%s", record[i].mis_num, record[i].student_name);
				for(j = 0; j < 48 - strlen(record[i].student_name); j++) {
                                printf(" ");
                        	}
				printf("%s\n", record[i].grades[2]);
			}
		}
		else if(!strcmp(temp_subject, "EM")) {
			 printf("MIS No. \t\tStudent Name  \t\t\t\t\t\t\t\t\tEM\n");
                         for(i = 0; i < class_strength; i++) {
                                printf("%s\t%s", record[i].mis_num, record[i].student_name);
				for(j = 0; j < 48 - strlen(record[i].student_name); j++) {
                                printf(" ");
                        	}	
				printf("%s\n", record[i].grades[3]);
			}
		}
		else if(!strcmp(temp_subject, "CAED")) {
                         printf("MIS No. \t\tStudent Name  \t\t\t\t\t\t\t\t\tCAED\n");
                         for(i = 0; i < class_strength; i++) {
                                printf("%s\t%s", record[i].mis_num, record[i].student_name);
				for(j = 0; j < 48 - strlen(record[i].student_name); j++) {
                                printf(" ");
                        	}
				printf("%s\n", record[i].grades[4]);
			}
		}
		else if(!strcmp(temp_subject, "PC")) {
                         printf("MIS No. \t\tStudent Name  \t\t\t\t\t\t\t\t\tPC\n");
                        for(i = 0; i < class_strength; i++) {
                                printf("%s\t%s", record[i].mis_num, record[i].student_name);
                		for(j = 0; j < 48 - strlen(record[i].student_name); j++) {
                                printf(" ");
                        	}
				printf("%s\n", record[i].grades[5]);
			}
		}
		else {
			printf("Subject not found in records. Enter Subject again.\n");
			goto LABEL_9;
		}
		goto LABEL_6;
	}
	else if(option == -1) {
		;
	}
	else {
		printf("Enter valid option: ");
		goto LABEL_7;
	}
	for(i = 0; i < student_strength; i++) {
                free(record[i].student_name);
                for(j = 0; j < 6; j++)
                        free(record[i].grades[j]);
        }
	return 0; 
}

int grade_credit(char ch[]) {
	if(!strcmp(ch, "AA")) {
		return AA;
	}
	else if(!strcmp(ch, "AB")) {
		return AB;
	}
	else if(!strcmp(ch, "BB")) {
		return BB;
	}
	else if(!strcmp(ch, "BC")) {
		return BC;
	}
	else if(!strcmp(ch, "CC")) {
		return CC;
	}
	else if(!strcmp(ch, "CD")) {
		return CD;
	}
	else if(!strcmp(ch, "DD")) {
		return DD;
	}
	else {
		return -1;
	}
}
