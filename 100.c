#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// (1)
int one (){
    int maior = 0;
    int n;

    printf("Insira uma sequência de números\n");
    while(n>0){
        assert(scanf("%d", &n) == 1);
        if (n>=maior)
            maior = n;
    }
    return maior;
}

// (2)
void two(){
    float media = 0;
    int i=0; //conta quantos números há na seq
    int soma = 0;
    int n;

    while (n!=0){
        printf("Insira um número: ");
        scanf("%d", &n);
        if (n == 0) break;
        soma += n;
        i++;
    }
    media = soma / i;
    printf("Média: %.2f", media);
}

// (3)
void three(){
    int first = 0,
        second = 0,
        number;

    while(number!= 0){
        printf("Insira um numero: ");
        scanf("%d", &number);

        if(number > first){
            second = first;
            first = number;
        } else if (number > second)
            second = number;

    }

    printf("Second: %d", second);
}

// (4) Calcula o número de bits = 1 de um num n
int bistUm (unsigned int n){
    int count=0; //vai contar os bits 
    while (n>0){
        if (n%2 == 1){ //verifica se o último bit é 1
            count++;
        }
        n/=2; //divide n por 2 para obter o próximo bit
    }
    return count;    
}


// (5) Número de bist a zeno no final da repres. de um número
int trailingZ (unsigned int n){
    int count=0; //conta os bits a 0
    //O while serve para percorrer os bist de n a partir do último
    while((n&1) == 0){ // o & compara o último bit com 1
        count++;
        n >>= 1; //desloca todos os bits de n uma posição para a direita
    }
    return count;
}

// alternativa sem o operador >>=
/*
int trailingZ (unsigned int n){
    int zero = 0;

    while(n!=0){
        if(n%2==0)
            zero++;
        n /= 2;
    }
    return zero;
}
*/


// (6) 
int qDig (unsigned int n){
    int count=1; //contabiliza o 1º digito
    while(n>=10){ // verdadeiro => n tem mais de um dígito
        count++;
        n/=10; //remover o último digito
    }
    return count;
}


// (7) Coloca s2 no fim de s1
// USANDO UMA STRING AUXILIAR
char *mystrcat (char s1[], char s2[]){
    char new[strlen(s1) + strlen(s2)];
    int i, j; //percorrem s1 e s2, respetivamente

    //percorrer s1
    for (i=0; i<(strlen(s1)); i++){
        new[i] = s1[i]; //coloca toda s1 na nova string
    }

    for(j=0; j<(strlen(s2)); j++){
        new[i+j] = s2[j]; // rastrear a posição atual na nova string
    }

    //indica o fim da string e retorna o ponteiro para a nova string
    new[strlen(s1)+strlen(s2)] = '\0'; 
    printf("%s\n", new);
    return new;
}

/*
É importante notar que a nova string new é criada dentro
da função e é uma variável local. Quando a função 
retorna, essa variável é destruída e O seu conteúdo não 
pode mais ser acessado. Se precisarmos de usar a string 
resultante fora da função, é recomendável alocar 
dinamicamente a nova string usando malloc() e liberar 
a memória alocada usando free() quando não for mais 
necessária.
*/

// NÃO USANDO UMA STRING AUXILIAR
char *mystrcat2 (char s1[], char s2[]){
    int i, j=0;
    //percorrer s1 até ao fim, sem fazer nada!
    for(i=0; s1[i]!='\0'; i++);

    while(s2[j] != '\0'){
        s1[i+j] = s2[j];
        j++;
    }
    s1[i+j] = '\0';
    return s1;
}



// (8)
char *mystrcpy (char dest[], const char source[]){
    int i=0, j;

    for (j=0; source[j]!='\0'; j++, i++){
        dest[i] = source[j];
    }
    dest[i] = '\0';
    return dest;
}
// OU
char *mystrcpy(char s1[], const char s2[]) {
    int i;
    for(i=0; s2[i]!='\0'; i++){
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return s1;
}


// (9)
int mystrcmp (char s1[], char s2[]){
    int i=0;
    //enquanto s1 e s2 forem iguais avança
    while(s1[i]!='\0' && s2[i]!='\0' && s1[i] == s2[i]){
        i++;
    }

    //se chegaram ambas ao fim retorna 0 (iguais)
    if (s1[i] == '\0' && s2[i]=='\0') return 0;
    else return s1[i]-s2[i];
}

/* Explicação do else:
Caso não sejam iguais, a função retorna a diferença 
entre o valor numérico do caractere em s1 e o valor 
numérico do caractere correspondente em s2. Se s1 for 
lexicograficamente menor que s2, o resultado será 
um número negativo. Se s1 for lexicograficamente maior 
que s2, o resultado será um número positivo.
*/


// (10)
char *mystrstr (char s1[], char s2[]){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j;

/*O primeiro loop percorre todos os caracteres de s1, 
menos o número de caracteres em s2.
*/
    for (i = 0; i <= len1 - len2; i++) {
        for (j = 0; j < len2; j++) {
            if (s1[i + j] != s2[j]) {
                break;
            }
        }
        /* O segundo loop percorre os caracteres de s2 
        e compara com os caracteres correspondentes 
        em s1. Se todos os caracteres forem iguais, 
        o segundo loop termina e a função retorna um 
        ponteiro para a posição de s1 onde s2 começa. 
        Caso contrário, o segundo loop seja interrompido 
        e o primeiro loop continue à procura a próxima 
        ocorrência.
        */
        if (j == len2) {
            return &s1[i];
        }
        /* Se o segundo loop termina com sucesso, 
        a condição if é atendida e a função retorna 
        um ponteiro para a posição atual de s1. Esta é 
        a posição onde s2 começa em s1.
        */
    }
    //se nunca encontrar o s2 em s1 retorna NULL
    return NULL;
}


// (11) Inverter uma string SEM string auxiliar
void strrev(char s[]){
    int i;
    int j = strlen(s)-1;
    char temp;
    for(i=0; i<j; i++){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
    }
    /*Enquanto i for menor que j, o loop troca o 
    caractere na posição i com o caractere na posição 
    j usando uma variável temp para armazenar 
    temporariamente o valor de s[i] durante a troca.
    */
}


// (12)
int vogais (char c){
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E'
        || c == 'i' || c == 'I' || c == 'o' || c == 'O' 
        || c == 'u' || c == 'U'){
            return 1;
        } else {
            return 0;
        }
}

void strnoV (char s[]){
    int i;
    int j=0;
    for (i=0; i<strlen(s); i++){
        if (vogais(s[i]) != 1){
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}

// (13)
void truncW (char t[], int n){
    int i, j = 0, contador = 0;

    for (i = 0; t[i]; i++) {
        if  (t[i] == ' ') {
            contador = 0; 
            t[j] = t[i];
            j++;
        } else {
            if (contador < n) {
                t[j] = t[i];
                j++;
                contador++;
            }
        }
    }
    t[j] = '\0';
}


// (14)
char charMaisfreq (char s[]){
    int i, j, maxCount=0;
    char maxChar = s['\0'];
    int len = strlen(s);

    if (len==0) return 0;

    for(i=0; i<len; i++){
        int count =1; //elemento s[i] j
        for(j=i+1; j<len; j++){ //todos os que vêm a seguir de s[i]
            if(s[i] == s[j]){
                count++;
            }
        }
        if(count > maxCount){
            maxCount = count;
            maxChar = s[i];
        }
    }
    return maxChar;
}


// (15)
int iguaisConsecutivos (char s[]){
    int i, maxCount=0;
    int len = strlen(s);

    if(len==0) return 0;

    for (i=0; i<len; i++){
        int count = 1;
        while(s[i] == s[i+1]){
            count++;
            i++;
        }
        if (count > maxCount){
            maxCount = count;
        }
    }
    return maxCount;
}


// 16) VER
int difConsecutivos (char s[]){
    int i=0, count, maior=0;
    while(s[i]!='\0'){
        count = 1;
        while (s[i] != s[i+1]){
            count++;
            i++;
        }
        if (count > maior){
            maior = count;
        }
        i++;
    }
    
    printf("O comprimento da maior sequência é %d\n", count);
    return maior;
}

//10 testes
//verifica se um char no ind i ocorreu na string até ao ind k
int not_in_prev(char str[], int k, int n) {
    int ans = 1, i;
    for(i = k; i < n; i++) {
        if(str[i] == str[n]) {
            return 0;
        }
    }
    return ans;
}

int difConsecutivos(char s[]) {
    int ans = 0, consec;
    int i, j;
    for( i = 0; s[i]; i++) {
        consec = 0;
        for(j = i; s[j]; j++) {
            if(not_in_prev(s,i,j)) consec++;
            else break;
        }
        if (consec > ans) ans = consec;
    }
    return ans;
}


// 17)
int maiorPrefixo (char s1 [], char s2 []){
    int i=0, comp=0;

    for(i=0; s1[i]; i++){
        if(s1[i] == s2[i]) comp++;
        else return comp;
    }

    printf("Comprimento %d\n", comp);
    return comp;
}

// 18)
//Neste caso não podíamos usar apenas o i para percorrer as duas strings
// pq como estamos a começar no fim de cada uma, os comprimentos são diferentes
int maiorSufixo (char s1 [], char s2 []){
    int i = strlen(s1)-1;
    int j = strlen(s2)-1;
    int comp=0;

    while(i>=0){
        if(s1[i] == s2[j]){
            comp++;
            i--;
        } else {
            return comp;
        }
    }
    return comp;
}

// 19) 
int sufPref (char s1[], char s2[]){
    int i;
    int j = 0, comp=0;

    for(i=0; s1[i]; i++){
        if (s1[i] == s2[i]){
            comp ++;
            j++;
        } else {
            comp = 0;
            j = 0;
        }
    }
    return comp;
}
/* Esta função percorre o s1 até encontrar a primeira letra
que sesteja no ínicio de s2. Daí no else colocar sempre j=0, para
começar a comparar sempre no incio de s2.
*/


// 20) Está a faltar UM caso !!
int contaPal (char s[]){
    int i=0, pal=0;
    int flag = 1; //vai indicar se estamos dentro de uma palavra (1 caso negativo)

    for(i=0; s[i]; i++){
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'){
            flag == 1;
        //se a flag for 1 estamos no começo de uma nova palavra
        } else if (flag == 1){
            flag = 0; //indica que agoa estamos numa palavra
            pal++;
        }
    }
    return pal;
}


// 21)
int isVogal (char c){
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
        return 1;
    }
    return 0;
}

int contaVogais (char s[]){
    int i=0, vogais=0;

    for (i=0; s[i]; i++){
        if (isVogal(s[i])==1) vogais++;
    }
    return vogais;
}


// 22)
int contida(char a[], char b[]) {
    int i, j, found;
    for (i = 0; a[i] != '\0'; i++) {
        found = 0; //vai determinar se a[i] foi encontrado em b
        //neste 2 cilo estamos a ver se a[i] está em b
        for (j = 0; b[j] != '\0'; j++) {
            if (a[i] == b[j]) {
                found = 1;
                break;
            }
        }
        //se o carater atual não for encontrado
        if (!found) {
            return 0;
        }
    }
    return 1;
}


// 23)
int palindorome (char s[]){
    int i, j, len = strlen(s);

    for (i=0, j= len-1; i < len/2; ++i, j--){
            if (s[i] != s[j]) return 0;
    }
    return 1;
}


// 24) Sem auxílio de uma string nova
// aaabaaabb b aaa
// abab
int remRep (char x[]){
    int i, j=0;

    for (i=0; x[i]; i++){
        if (x[i] != x[i+1] || x[i+1] == '\0'){
            x[j] = x[i];
            j++;
        }
    }

    x[j] = '\0';
    return j;
}


// 25) Explicação no Notion
int limpaEspacos (char s[]){
    int i, j;

    for(i=0; s[i]; i++){
        if (s[i] == ' ' && s[i+1] == ' '){
            for(j=i+1; s[j]; j++)
                s[j] = s[j+1];
            i--;
        }
    }
    return i;
}

// 26) Explicação no Notion
void insere (int v[], int N, int x){
    int i, j;
    for (i=0; i<N; i++){
        if (v[i] > x){
            for(j=N; j>i; j--){
                v[j] = v[j-1];
            }
            v[i] = x;
        }
    }
    v[N] = x; //caso o x seja maior do que qq outro
}

// 27)
void merge (int r [], int a[], int b[], int na, int nb){
    int i, j, k;
    for(k=0, i=0, j=0; i<na && j< nb; k++){
        if(a[i] <= b[j]){
            r[k] = a[i];
            i++;
        } else {
            r[k] = b[j];
            j++;
        }
    }
    //caso a[na] ainda tenha mais elementos
    for(; i<na; i++, k++)
        r[k] = a[i];
    //caso b[nb] ainda tenha mais elementos
    for(; j<nb; j++, k++)
        r[k] = b[j];
}

// 28) 1-> ordenado | 0-> não ordenado
int crescente (int a[], int i, int j){
    int r=1; //verdadeiro
    while(i<j){
        if(a[i] > a[i+1]){
            r=0;
            break;//aqui o ciclo while para imediatamente
        }
        i++;
    }
    return r;
}


// 29)
int retiraNeg (int v[], int N){
    int i, j;
    for(i=0, j=0; i<N; i++){
        if (v[i] > 0){ //se for negativo tiramos 
            v[j] = v[i];
            j++;
        }
    }
    return j;
}

// 30) ORDENADO POR ORDEM CRESCENTE! -> Explicação no Notion
// REVER
int menosFreq(int v[], int N) {
    int i, freqAtual = 1, freqMenor = N, menosFreq = v[0];

    for (i = 1; i < N; i++) {
        if (v[i] == v[i-1]) {
            freqAtual++;
        } else {
            if (freqAtual < freqMenor) {
                freqMenor = freqAtual;
                menosFreq = v[i-1];
            }
            freqAtual = 1;
        }
    }

    if (freqAtual < freqMenor) {
        menosFreq = v[N-1];
    }

    return menosFreq;
}


// 31) Retorna o mais frequente num array ordenado cresc
int maisFreq (int v[], int N){
    int i, freqAtual=1, freqMaior = 1, maisFreq = v[0];
    
    for (i=0; i<N; i++){
        if (v[i] == v[i+1]){
            freqAtual++;
        } else {
            if(freqAtual > freqMaior){
                freqMaior = freqAtual;
                maisFreq = v[i];
            }
            freqAtual = 1;
        }
    }
    if (freqAtual > freqMaior){
        maisFreq = v[N-1];
    }
    return maisFreq;
}

// 32)
int maxCresc (int v[], int N){
    int i, j, comp=1, maiorSeq = 1;
    for(i=0, j=i+1; i<N; i++){
        while(v[i]<= v[j] && j<N){
            if (v[i] < v[i+1]){
            comp++;
        } else {
            if(comp > maiorSeq){
                maiorSeq = comp;
            }
            comp=1;
        }
        }
    }
    return maiorSeq;
}


//33) REVER
int elimRep(int v[], int n) {
    int i, j, newSize = 1; // novo tamanho do vetor sem repetições
    for (i = 1; i < n; i++) {
        for (j = 0; j < newSize; j++) {
            if (v[i] == v[j]) { // se encontrarmos um elemento igual, interrompemos a busca
                break;
            }
        }
        if (j == newSize) { // se chegamos ao fim sem encontrar um elemento igual, adicionamos o elemento ao vetor resultante
            v[newSize] = v[i];
            newSize++;
        }
    }
    return newSize;
}


// 34) REVER
int elimRepOrd(int v[], int n) {
    int j, i = 0; // índice do último elemento não repetido
    for (j = 1; j < n; j++) {
        if (v[i] != v[j]) { // se encontrarmos um elemento diferente do último não repetido, adicionamos ao vetor resultante
            v[i] = v[j];
            i++;
        }
    }
    return i+1; // o novo tamanho do vetor é i+1
}


// 35) Queremos ver quantos têm em comum a e b
int comunsOrd (int a[], int na, int b[], int nb){
    int i=0, j=0, c=0; //c conta os comuns
    while(i<na & j<nb){
        if (a[i] == b[j]){
            c++;
            i++;
            j++; 
        } else {
            if (a[i] < b[j]){
                i++;
            }else{
                j++;
            }
        }
    }
    return c;
}

// 36)
//Verifica se um elemento pertence a um array
int pertence (int x, int a[], int na){
    int i;
    for(i=0; i<na; i++){
        if (x == a[i]){
            return 1;
        }
    }
    return 0;
}

int comuns (int a[], int na, int b[], int nb){
    int i, j, comuns = 0;

    for(i=0; i<na; i++){
        if (pertence(a[i],b,nb) == 1){
            comuns++;
        }
    }
    return comuns;
}


// 37)
int minInd (int v[], int n){
    int i, menor;
    for (i=0; i<n; i++){
        if (v[i] < v[menor])
            menor = i;
    }
    return menor;
}


// 38)
/* Ac[3] => v[0] + v[1] + v[2] + v[3]
*/
void somasAc (int v[], int Ac [], int N){
    int i, soma=0;
    for(i=0; i<N; i++){
        soma += v[i];
        Ac[i] = soma;
    }
}
/* EXPLICAÇÃO:
    N é o tamanho dos vetores!!
    A soma é usada para calcular as somas acumuladas dos elementos de v.
    Percorremos v e vamos somando os seus valores até ao N.
    Por fim, preenchemos o Ac no índice em que estamos com a soma dos elementos de v.
*/


// 39)
/* EXEMPLO DE UMA MATRIZ TRIANGULAR SUP
    [[1, 2, 3]
     [0, 2, 1]
     [0, 0, 3]]
*/
int triSup (int N, float m [N][N]){
    int i, j;

    for(i=1; i<N; i++){
        for(j=0; j<i; j++){
            if(m[i][j] != 0.0) return 0; // não é triangular sup
        }
    }
    return 1; //é triangular sup
}


// 40) Transposta = trocar as linhas com as colunas
/* EXEMPLO 
    [[1, 2, 3]   transposta =>  [[1, 2, 4]
     [2, 2, 1]                   [2, 2, 5]
     [4, 5, 3]]                  [3, 1, 3]]
*/
void transposta (int N, float m [N][N]){
    int i, j;
    float t;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            t = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = t;
        }
    }
}


// 41) Soma 'b' a 'a'
void addTo (int N, int M, int a [N][M], int b[N][M]){
    int i, j; // i linhas e j colunas
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            a[i][j] += b[i][j];
        }
    }
}


// 42)
int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    //percorrer todos os elementos dos arrays v1 e v2
    //e armazenamos a união no array r
    for(i=0; i<N; i++){
        r[i] = v1[i] || v2[i];
        //verifica se o elem está em pelo menos um dos conjunto
    }
    return 0;
}


// 43)
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0; i<N; i++){
        r[i] = v1[i] && v2[i];
    }
    return 0;
}


// 47)
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;

    for(i=0; i<N; i++){
        switch(mov[i]){
            case Norte: inicial.y++;
                break;
            case Oeste: inicial.x--;
                break;
            case Sul: inicial.y--;
                break;
            case Este: inicial.x++;
                break;
        }
    }
    return inicial;
}


// 48)
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){

}


// PARTE 2

typedef struct lligada {
    int valor;
    struct lligada *prox;
} * LInt;

// 1) 10 testes
int length (LInt l){
    int comp = 0;
    while(l != NULL){
        comp += 1;
        l = l->prox;
    }
    return comp;
}

// 2)
void freeL (LInt l){
    LInt aux;
    while(l != NULL){
        aux = l->valor;
        free(l);
        l = aux;
    }
}

// 3)
void imprimeL (LInt l){
    while(l != NULL){
        printf("%d ", l->valor);
        l = l->prox;
    }
    printf("\n");
}

// 4) 10 testes 
LInt reverseL (LInt l){
    LInt atual = l;
    LInt anterior = NULL;
    LInt proximo;

    while(atual != NULL){
        //trocar a ligação:
        proximo = atual->prox;
        atual->prox = anterior; //em vez de apontar para o que vem a seguir, aponta para o anterior trocando assim a ordem 
        //avançar na lista:
        anterior = atual; //passamos o valor do atual para o anterior para prosseguir o racionio
        atual = proximo;
    }

    return anterior;
}


// 5) 10 testes
void insertOrd (LInt *l, int x){
    //Alocamos um nó com o x
    LInt new = (LInt)malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;

    /*Verifica se a lista está vazia ou se o valor do novo nó 
    é menor do que o valor do primeiro nó atual da lista. 
    Se sim, o novo nó é inserido no início da lista.
    */
    if(*l == NULL || x < (*l)->valor){
        new->prox = (*l); //insere no inicio da lista
        *l = new;
    } else {
        LInt atual = *l;
        while(atual->prox != NULL && atual->prox->valor < x){
            atual = atual->prox;
        }
        new->prox = atual;
        atual->prox = new;
    }
}


// 6) 10 testes
// 1 -> x não existe
// 0 -> x existe
int removeOneOrd (LInt *l, int x){
    if (*l == NULL) return 1;

    if((*l)->valor == x){
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
        return 0;
    }

    LInt prev = (*l);
    LInt curr = (*l)->prox;

    while(curr != NULL && curr->valor != x){
        prev = curr;
        curr = curr->prox;
    }

    //não encontramos x na lista
    if(curr == NULL) return 1;

    //encontramos x na lista
    prev->prox = curr->prox;
    free(curr);
    return 0;
}


// 7) 10 testes REVER!!
merge (LInt *r, LInt a, LInt b){
    while(a != NULL || b!= NULL){
        if(a != NULL && b!= NULL && a->valor < b->valor || b == NULL){
            *r = a;
            a = a->prox;
        } else {
            *r = b;
            b = b->prox;
        }
        r = &((*r)->prox);
    }
    *r = NULL;
}


// 8) 10 testes
// ATENÇÃO : A LISTA PODE NÃO ESTAR ORDENADA!
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l != NULL){
        if(l->valor < x){
            *mx = l;
            l = l->prox;
            mx = &((*mx)->prox);
        } else {
            *Mx = l;
            l = l->prox;
            Mx = &((*Mx)->prox);
        }
    }
    *mx = NULL;
    *Mx = NULL;
}


// 9) 10 testes
// ATENÇÃO : A LENGTH DA LISTA DEVE SER UMA FUNÇÃO CRIADA
// No caso estamos a usar a primeira que fizemos neste ficheiro
LInt parteAmeio (LInt *l){
    int meio = length(*l)/2;

    if(meio == 0) return NULL;

    LInt y = (*l);
    LInt prev = NULL;
    int i;
    for(i=0; i<meio; i++){
        prev = (*l);
        (*l) = (*l)->prox;
    }
    prev->prox = NULL;
    return y;
}


// 10) 10 testes
// TODAS AS OCORRENCIAS
int removeAll (LInt *l, int x){
    int count=0;
    LInt curr = *l; //vai percorrer l sem a alterar
    LInt prev = NULL; //vai guardar a lista sem x

    while(curr != NULL){
        if(curr->valor == x){
            //ver se o nó é o primeiro da lista
            if(prev == NULL){ //se for o primeiro da lista
                *l = curr->prox;
            } else {
                prev->prox = curr->prox; //atualizamos a lista prev sem o x
            }

            //remove uma ocorrencia de x
            LInt temp = curr->prox;
            free(temp);
            curr = temp;
            count++;

        } else {
            prev = curr;
            curr = curr->prox;
        }
    }

    return count;
}


// 11) 10 testes
// PODE NÃO ESTAR ORDENADA!
int removeDups (LInt *l){
    int rep = 0;

    while(*l){
        LInt anterior = NULL;
        LInt seguinte = (*l)->prox;
        for(; seguinte->valor; seguinte = anterior->prox){
            if(seguinte->valor == (*l)->valor){
                rep++;
                anterior->prox = seguinte->prox;
                free(seguinte);
            } else {
                anterior = seguinte; 
            }
        }
        (*l) = (*l)->prox;
    }
    return rep;
}


// 12) 10 testes
int maiorDaLista (LInt *l){
    int maior = 0;
    while(*l){
        if ((*l)->valor > maior){
            maior = (*l)->valor;
        }
        l = &((*l)->prox);
    }
    return maior;
}

int removeMaiorL (LInt *l){
    int maior = maiorDaLista(*l);

    while((*l)->valor !=  maior){
        l = &((*l)->prox);
    }

    LInt temp = (*l)->prox;
    free(*l); //onde está o maior
    *l = temp;

    return maior;
}


// 13)
void init (LInt *l){
    
    while((*l)->prox !=  NULL){
        l = &((*l)->prox);
    }

    LInt temp = (*l)->prox;
    free(*l);
    (*l) = temp;
}


// 14) 10 testes
void appendL (LInt *l, int x){
    
    while(*l){
        l = &((*l)->prox);
    }

    LInt novoElem;
    novoElem = malloc(sizeof(struct lligada));
    novoElem->valor = x;
    novoElem->prox = NULL;

    (*l) = novoElem; 
}


// 15) 10 testes
void concatL (LInt *a, LInt b){
    while(*a){
        a = &((*a)->prox);
    }

    *a = b;
}


// 16)
LInt cloneL (LInt l){
    if (l == NULL) return NULL; // lista vazia

    //inicialiar a lista
    LInt nova = malloc(sizeof(struct lligada));
    nova->valor = l->valor;
    nova->prox = NULL;

    LInt curr = nova;
    l = l->prox;

    while (l != NULL) {
        //aloca espaço para um nó que depois adiciona na lista
        LInt novo_no = malloc(sizeof(struct lligada));
        novo_no->valor = l->valor;
        novo_no->prox = NULL;

        curr->prox = novo_no;
        curr = novo_no;

        l = l->prox;
    }

    return nova;
}


// 17) 10 testes
// REVER
LInt cloneRev (LInt l){
    LInt nova = NULL, nodo;

    while(l){
        nodo = malloc(sizeof(struct lligada));
        nodo->valor = l->valor;
        nodo->prox = nova;
        nova = nodo;
        l = l->prox;
    }

    return nova;
}


// 18) 10 testes
int maximo (LInt l){
    int max = 0;

    while(l!=NULL){
        if(l->valor > max){
            max = l->valor;
        }
        l = l->prox;
    }

    return max;
}


// 19) 10 testes
int take (int n, LInt *l){
    int i=0;
    while(*l && i<n){
        l = &((*l)->prox);
        i++;
    }

    //chega a posição n
    while(*l){
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }

    return i;
}


// 20) 10 testes
int drop (int n, LInt *l){
    int i=0;
    while(*l && i<n){
        i++;
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }

    return i;
}


// 21) 10 testes
LInt Nforward (LInt l, int N){
    int i=0;
    while(l!=NULL && i<N){
        i++;
        l = l->prox;
    }

    //encontrou a posição N
    return l;
}


// 22) 10 testes
int listToArray (LInt l, int v[], int N){
    int i=0;

    while(l && i<N){
        v[i] = l->valor;
        l = l->prox;
        i++;
    }
    
    return i;
}


// 23) 10 testes
// REVER
LInt arrayToList (int v[], int N){
    int i;
    LInt prev = NULL;
    LInt l = NULL;
    
    for(i=0; i<N; i++){
        //criamos um nó para alocar na lista
        LInt no = malloc(sizeof(struct lligada));
        no->valor = v[i];
        no->prox = NULL;

        if(prev == NULL){
            l = no;
        } else {
            prev->prox = no;
        }
        prev = no;
    }

    return l;
}


// 24 10 testes
LInt somasAcL (LInt l){
    LInt nova;
    LInt *r = &nova;
    int acc = 0;

    for (; l; l = l->prox) {
        acc += l->valor;
        *r = malloc(sizeof(struct lligada));
        (*r)->valor = acc;
        r = &(*r)->prox;
    }

    *r = NULL; //diz que (*r)->prox = NULL (termina a lista)

    return nova;
}


// 25) 10 testes
void remreps (LInt l){
    while(l){
        LInt *next = &(l->prox);
        while(*next && (*next)->valor == l->valor){
            //encontramos repetidos então vamos apagar
            LInt temp = (*next)->prox;
            free(*next);
            *next = temp;
        }
        l = l->prox;
    }
}


// 26) 10 testes
// REVER
LInt rotateL (LInt l){
    if (l==NULL || l->prox == NULL) return l;

    LInt lista = l; //aponta para o inicio da lista
    LInt segundo = l->prox; //aponta para a lista sem o primeiro

    while(lista->prox != NULL){
        lista = lista->prox;
    }
    //encontramos o último elemento
    lista->prox = l;
    l->prox = NULL;

    return segundo;
}


// 27) 10 testes
// REVER
LInt parte (LInt l){
    if (l == NULL || l->prox == NULL) return NULL;

    LInt pares = l->prox; //a lista y começa com o segundo elem da lista
    l->prox = l->prox->prox; // retira o segundo elem da lista
    pares->prox = parte(pares->prox);
    return pares;
}


// -------- ARVORES BINÁRIAS -------------

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} *ABin;


// 28) 10 testes
int altura (ABin a){
    int alt = 0;

    if (a != NULL){
        if(altura(a->esq) > altura(a->dir)){
            alt = 1 + altura(a->esq);
        } else {
            alt = 1 + altura(a->dir);
        }
    }

    return alt;
}


// 29) 10 testes 
ABin cloneAB (ABin a){
    ABin copia = malloc(sizeof(struct nodo));

    if(a == NULL) return NULL;

    copia->valor = a->valor;
    copia->esq = cloneAB(a->esq);
    copia->dir = cloneAB(a->dir);

    return copia;
}


// 30) 10 testes
void mirror (ABin *a){
    if(*a){
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
    }
}


// 31) 10 testes
// INORDER: esq -> raiz -> dir
void inorder (ABin a, LInt *l){
    if(!a){
        (*l) = NULL;
    } else {
        //travessia à esquerda
        inorder(a->esq, l);

        //avançar
        while(*l){
            l = &((*l)->prox);
        }

        //Colocar o valor da raiz na lista
        *l = malloc (sizeof(struct lligada));
        (*l)->valor = a->valor;

        //tarvessia à dir
        inorder(a->dir, &(*l)->prox);
    }
}


// 32) 10 testes
// PREORDER: raiz -> esq -> dir
void preorder (ABin a, LInt *l){
    if(!a){
        (*l) = NULL;
    } else {
        //colocar a raiz na lista
        *l = malloc (sizeof(struct lligada));
        (*l)->valor = a->valor;

        //travessia à esq
        preorder(a->esq, &(*l)->prox);

        //avançar na lista
        while(*l){
            l = &((*l)->prox);
        }

        //travessia na dir
        preorder(a->dir, l);
    }
}


// 33) 10 testes
// POSORDER: esq -> dir -> raiz
void posorder (ABin a, LInt *l){
    if(!a){
        (*l) = NULL;
    } else {
        //travessia na esquerda
        posorder(a->esq, l);

        //avançar na lista
        while(*l){
            l = &((*l)->prox);
        }

        //travessia na dir
        posorder(a->dir, l);

        //avançar
        while(*l){
            l = &((*l)->prox);
        }

        //inserir raiz 
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
    }
}


// 34) 10 testes
int depth (ABin a, int x){
    if(a==NULL) return -1;
    
    if(a->valor == x) return 1;
    
    int e = depth(a->esq, x);
    int d = depth(a->dir, x);
    
    if(e == -1 && d == -1) return -1;
    if(e == -1) return (1+d);
    if(d == -1) return (1+e);
    if(e < d){
        return 1+e;
    } else {
        return 1+d;
    }
}


// 35)
int freeAB (ABin a){
    int rem = 0;
    if(!a) return 0;

    rem = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a);

    return rem;
}



// 36) 10 testes
int pruneAB (ABin *a, int l){
    int rem = 0;

    if(a == NULL) return rem;
    if(*a) {
        if(l==0){ //remover a partir da raiz
            rem += (1 + pruneAB(&(*a)->esq, l) + pruneAB(&(*a)->dir, l));
            free(*a);
            (*a) = NULL;
        } else { //para baixo da raiz
            rem += (pruneAB(&(*a)->esq, l-1) + pruneAB(&(*a)->dir, l-1));
        }
    }

    return rem;
}


// 37) 10 testes
int iguaisAB (ABin a, ABin b){
    if(a == NULL && b == NULL) return 1;

    if(a == NULL || b==NULL) return 0;

    if(a->valor != b->valor) return 0;

    return iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
}


// 38) 10 testes
LInt concatenaL (LInt a, LInt b){
    if(!a) return b;
    LInt temp = a;
    while (temp->prox){
        temp = temp ->prox;
    }
    temp->prox = b;
    return a;
    
}

LInt nivelL (ABin a, int n){
    LInt l;
    //Caso a árvore não exista
    if (!a) return NULL;

    //Caso o nível seja 1 (i.e, o da raíz)
    if (n == 1){
        l = malloc(sizeof(struct lligada));
        l->valor = a->valor;
        l->prox = NULL;
        return l;
    }

    //Caso o nível seja >1
    return concatenaL(nivelL(a->esq, n-1), nivelL(a->dir,n-1));
}


// 39) 10 testes
int nivelV(ABin a, int n, int v[]) {
    if (a == NULL || n < 1) {
        return 0;
    } else if (n == 1) {
        v[0] = a->valor;
        return 1;
    } else {
        int e = nivelV(a->esq, n-1, v);
        int d = nivelV(a->dir, n-1, v+e);
        return e + d;
    }
}


// 40) inorder
int dumpAbin (ABin a, int v[], int N){
    if (a == NULL || N==0) return 0;
    //travessia pela esq
    int e = dumpAbin(a->esq, v, N);
    if(e == N) return N; //limite alcançado
    //colocar a raiz
    v[e] = a->valor;
    e++;
    //travessia pela direira
    int d = dumpAbin(a->dir, &v[e], N-e);
    return e+d; 
}


// 41) 10 testes
// REVER
ABin somasAcA (ABin a){
    if (a == NULL) return NULL;
    
    ABin nova = malloc (sizeof(struct nodo));
    nova->esq = somasAcA(a->esq);
    nova->dir = somasAcA(a->dir);
    nova->valor = a->valor + (nova->esq ? nova->esq->valor : 0) + (nova->dir ? nova->dir->valor : 0);
}


// 42) 10 testes
int contaFolhas (ABin a){
    int folhas = 0;
    if(!a) return 0;

    int e = contaFolhas(a->esq);
    int d = contaFolhas(a->dir);

    if(a->esq == NULL && a->dir==NULL) folhas=1;
    if(!a->dir && a->esq) folhas = e;
    if(a->dir && !a->esq) folhas = d;
    if(a->dir && a->esq) folhas = e+d;

    return folhas;
}


// 43) 10 testes
// ATENÇÃO ÀS LINHAS 1662 E 1663
ABin cloneMirror (ABin a){
    if(!a) return NULL;

    ABin nova = malloc(sizeof(struct nodo));
    nova->valor = a->valor;
    nova->esq = cloneMirror(a->dir);
    nova->dir = cloneMirror(a->esq);

    return nova;
}


// 44) 10 testes
int addOrd (ABin *a, int x){
    while(*a){
        if((*a)->valor == x) return 1; //já existe
        if((*a)->valor > x){
            a = &((*a)->esq); //vamos procurar na esq
        } else {
            a = &((*a)->dir);
        }
    }

    //se a árvore estiver vazia
    ABin nova = malloc(sizeof(struct nodo));
    nova->valor = x;
    nova->esq = nova->dir = NULL;
    (*a) = nova;

    return 0;
}


// 45) 10 testes
// 1-> pertence || 0 -> não pertence
int lookupAB (ABin a, int x){
    if(!a) return 0;

    if(a->valor == x) return 1;
    if(a->valor > x) lookupAB(a->esq, x);
    else lookupAB(a->dir, x);
}


// 46) 10 testes
// REVER
int depthOrd (ABin a, int x){
    int nivel = 1;

    while(a != NULL){
        if(a->valor == x) return nivel;
        else if (x < a->valor) a = a->esq;
        else if (x > a->valor) a = a->dir;
        nivel++;
    }

    return -1;
}


// 47) 10 testes
//Os maiores elementos de QQ árvore estão SEMPRE na direita!!
//Vai andar sempre para a direita até não haver mais nada à direita, ou seja, encontrou o maior
int maiorAB (ABin a){
    while(a->dir){
        a = a->dir;
    }
    return a->valor;
}


// 48) 10 teste
//Os maiores elementos de QQ árvore estão SEMPRE na dir
void removeMaiorA (ABin *a){
    if(!(*a)->dir){ // maior está na raíz
        ABin temp = (*a)->esq;
        free(*a);
        (*a) = temp;
    } else {
        removeMaiorA(&(*a)->dir);
    }
}


// 49) 10 testes
int quantosMaiores (ABin a, int x){
    if(!a) return 0;

    if(a->valor <= x) return quantosMaiores(a->dir,x);
    if(a->valor > x) return 1 + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x);
}


// 50) 10 testes
// NÃO ESQUECER DE DEFINIR A LENGTH
void listToBTree (LInt l, ABin *a){
    if(!l) return NULL;

    ABin new = malloc(sizeof(struct nodo));
    int meio = length(l) / 2; //raiz
    LInt temp = l, prev = NULL;
    int i;

    // percorre até ao meio e guarda o nó anterior em prev
    for(i = 0; i < meio; i++) {
        prev = temp;
        temp = temp->prox;
    }

    //copia o meio para a raiz
    new->valor = temp->valor;
    new->esq = new->dir = NULL;
    if(prev) prev->prox = NULL;
    
    //se o meio não é o 1º da lista, constroi a arv esq
    if(l != temp) listToBTree(l,&(new->esq));
    //se o meio não é o 1º da lista, constroi a arv dir
    if(temp->prox) listToBTree(temp->prox,&(new->dir));
    (*a) = new;
}


// 51) 10 testes
// Função auxiliar que retorna o nó com o valor máximo de uma árvore
ABin maior(ABin a) {
    while (a->dir != NULL) a = a->dir;
    return a;
}

// Função auxiliar que retorna o nó com o valor mínimo de uma árvore
ABin menor(ABin a) {
    while (a->esq != NULL) a = a->esq;
    return a;
}

int deProcura (ABin a){
    if(!a) return 1; //vazia

    if (a->esq != NULL && (maior(a->esq))->valor > a->valor) return 0;
    if (a->dir != NULL && (menor(a->dir))->valor < a->valor) return 0;
    
    return deProcura(a->esq) && deProcura(a->dir);
}