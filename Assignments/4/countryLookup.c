#include<stdio.h>

//Tracy Michaels
//this program prompts the user to enter a countries code and 
//if it exists the prints the name of the country

#define NUM_CODES 20

//struct containing country codes from section 16.3 in book
struct dialing_code{
    char *country;
    int code;
};

const struct dialing_code country_code[NUM_CODES] = 
    {
        {"Argentina", 54}, {"Bangladesh", 880},
        {"Brazil",    55}, {"Burma",       95},
        {"China",     86}, {"Colombia",    57},
        {"Congo",    243}, {"Egypt",       20},
        {"Ethopia",  251}, {"France",      33},
        {"Germany",   49}, {"India",       91},
        {"Indonesia", 62}, {"Iran",        98},
        {"Italy",     39}, {"Japan",       81},
        {"Mexico",    52}, {"Nigera",     234},
        {"Poland",    48}, {"Russia",       7}
    };

void lookup(int);

int main(){
    
    int input;

    printf("Enter coutnry code: ");
    scanf("%d", &input);
    lookup(input);
    return 0;
}

//checks if entered code is in country_codes
//prints country if it is
void lookup(int n){
    int i = 0;
    for(; i < NUM_CODES; i++){
        if(country_code[i].code == n){
            printf("%s\n", country_code[i].country);
            return;
        }
    }
    printf("Code not found\n");
}