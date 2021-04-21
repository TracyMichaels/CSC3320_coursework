#include<stdio.h>
#include<string.h>

//Tracy Michaels
//This program registers patients for the covid cavvine
//and displays relavent information about the patients

//ran out of time to make this more robust/performant :(


//struct for patient
struct Patient{
    char first_name[20];
    char last_name[20];
    char birth_date[10];
    char age[2];
    char sex[7];
    char dose_num[1];
    char previous_dose[10];
    char vacc_type[15];
    char zip[5];
    char patientID[9];
};

void _register(struct Patient);
void generate_code(struct Patient);
void retrive(struct Patient);
void display_prompt();


int main(){
    
    int input;
    struct Patient patients[20];
    int num_patients = 0;
    char *idIn;
    
    //main logic loop
    do{
        display_prompt();
        scanf("%d", &input);

        switch(input){
            case 1:
                if(num_patients >= 20) {
                    printf("Patient roster full");
                    break;
                }
                _register(patients[num_patients]);
                num_patients++;
                break;
            case 2:
                printf("Type patient id: ");
                scanf("%s", idIn);
                int i;
                for(i = 0; i < num_patients; i++){
                    if(strcasecmp(idIn, patients[i].patientID) == 0) {
                        retrive(patients[i]);
                    }
                }
                printf("Invalid Id\n");
                break;
            case 3:
                break;
            default:
                printf("Invalid Entry\n");
                break;
        }
    } while(input != 3);


    return 0;
} 

//diaplays a prompt to the user to start registration process
void display_prompt(){
    printf("\n*********Covid Vaccine Registration**********\n\n");
    printf("(1) Register a Patient\n");
    printf("(2) Display Patient Info\n");
    printf("(3) Quit\n");
    printf("Type number of selection: ");
}

//registers patient and saves infor in a struct
void _register(struct Patient patient){
    char in[20];
    printf("First Name: ");
    scanf("%20s", &in);
    strcpy(patient.first_name, in);
    printf("Last Name: ");
    scanf("%20s", &in);
    strcpy(patient.last_name, in);
    printf("Date of Birth (mm/dd/yyyy): ");
    scanf("%10s", &in);
    strcpy(patient.birth_date, in);
    printf("Age: ");
    scanf("%2s", &in);
    strcpy(patient.age, in);
    printf("Sex (Male/Female/Other): ");
    scanf("%7s", &in);
    strcpy(patient.sex, in);
    printf("Dose number (1 or 2): ");
    scanf("%1s", &in);
    strcpy(patient.dose_num, in);
    printf("Previous dose (mm/dd/yyy) or NA: ");
    scanf("%10s", &in);
    strcpy(patient.previous_dose, in);
    printf("Vaccine type (Pfizer/Moderna/Johnson&Johnson): ");
    scanf("%15s", &in);
    strcpy(patient.vacc_type, in);
    printf("Zip code: ");
    scanf("%5s", &in);
    strcpy(patient.zip, in);
    generate_code(patient);
}

//generate unique code for each patient based on patient info
void generate_code(struct Patient patient){

    patient.patientID[0] = patient.first_name[0];
    patient.patientID[1] = patient.last_name[0];
    patient.patientID[2] = patient.age[0];
    patient.patientID[3] = patient.age[1];
    patient.patientID[4] = patient.vacc_type[0];
    patient.patientID[5] = patient.zip[2];
    patient.patientID[6] = patient.zip[3];
    patient.patientID[7] = patient.zip[4];
    patient.patientID[8] = '\0';
    printf("PatientID %s\n", patient.patientID);  
}

//displays patient information
void retrive(struct Patient patient){
    printf("\nFirst Name: %s\n", patient.first_name);
    printf("Last Name: %s\n", patient.last_name);
    printf("Date of Birth (mm/dd/yyyy): %s\n", patient.birth_date);
    printf("Age: %s\n", patient.age);
    printf("Sex: %s", patient.sex);
    printf("Dose number: %s\n", patient.dose_num);
    printf("Previous dose (mm/dd/yyy): %s\n", patient.previous_dose);
    printf("Vaccine type: %s\n", patient.vacc_type);
    printf("Zip code: %s\n", patient.zip);
    printf("Patient ID: %s", patient.patientID);

}