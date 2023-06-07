int main() {
    printf("Programa de Exemplo - Controle de Memória com Referências\n\n");

    int* ptr1 = (int*) malloc2(sizeof(int)); // Aloca memória utilizando malloc2
    int* ptr2 = (int*) malloc2(sizeof(int));

    *ptr1 = 10; // Atribui o valor 10 ao ponteiro 1
    *ptr2 = 20; // Atribui o valor 20 ao ponteiro 2

    printf("Situação da memória após alocação:\n");
    dump(); // Exibe a situação da memória

    atrib2(ptr1, ptr2); // Atribui o valor de ptr2 a ptr1

    printf("Situação da memória após atribuição:\n");
    dump(); // Exibe a situação da memória novamente

    free(ptr1); // Libera a memória de ptr1
    free(ptr2); // Libera a memória de ptr2

    printf("Situação final da memória:\n");
    dump(); // Exibe a situação final da memória

    return 0;
}
