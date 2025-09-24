#include <time.h>
#include <stdio.h>

int main() {

    struct tm *data_hora_atual;

    time_t segundos;

    time(&segundos);

    data_hora_atual = localtime(&segundos);



    printf("ano: %d", data_hora_atual->tm_year+1900);


    return 0;
}
