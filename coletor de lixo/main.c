int main() {
    printf("Programa de Exemplo - Controle de Memória com Referências\n\n");

    int* v = (int*) malloc2(sizeof(int)); // Aloca memória utilizando malloc2
    *v = 10; // Atribui o valor 10 ao ponteiro v

    int* w = (int*) malloc2(sizeof(int)); // Aloca memória utilizando malloc2
    dump(); // Exibe a situação da memória

    *w = 20; // Atribui o valor 20 ao ponteiro w

    atrib2(v, w); // Atribui o valor de w a v
    dump(); // Exibe a situação da memória novamente

    char* c = "Z"; // Modificado para uma string válida
    dump(); // Exibe a situação da memória

    atrib2(w, NULL); // Atribui NULL a w
    dump(); // Exibe a situação da memória novamente

    return 0;
}