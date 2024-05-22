Este programa foi desenvolvido em uma atividade da faculdade para avaliar o desempenho de algoritmos de ordenação. Abaixo estão algumas informações importantes sobre o funcionamento e a utilização do programa:

1. Compilação:
Certifique-se de que todos os arquivos de inclusão necessários estão corretamente configurados no diretório "../include" e que todas as implementações dos algoritmos de ordenação estão presentes.

Certifique-se também das regras de compilação inseidas no makefile

3. Uso:
Para executar o programa, você deve usar o make para compilar o progrma. Em seguida executar o executavel na pasta /bin ./pa1.out
Em seguida coloque o codigo a seguir:

-z <int>        (vector size)

-s <int>        (initialization seed)

-a <s|i|q|q3|qi|q3i|h|rs>       (algorithm)

            s   selection
            i   insertion
            q   quicksort
            q3  quicksort+median3
            qi  quicksort+insertion
            q3i quicksort+median3+insertion
            h   heapsort
            rs  recursive selection
   
ficaria parecido com isso:
<code>./pa1.out -z 10 -s 1 -a q</code>

Onde:
- <algoritmo> é o algoritmo de ordenação a ser avaliado (veja as opções disponíveis no arquivo "main.h").
- <semente> é a semente para a geração de números aleatórios.
- <tamanho> é o tamanho do vetor de entrada.

3. Opções de algoritmo:
O programa suporta os seguintes algoritmos de ordenação:
- Insertion Sort
- Selection Sort
- Quick Sort
- Quick Sort (media 3)
- Quick Sort com Insertion Sort
- Quick Sort (media 3) com Insertion Sort
- Shell Sort
- Recursive Selection Sort

4. Exemplo de uso:
Por exemplo, para executar o programa com o algoritmo Quick Sort, semente 3 e vetor de tamanho 1000, você pode usar o seguinte comando:

<code>-z 1000 -s 3 -a q</code>

6. Saída:
O programa fornecerá informações sobre o desempenho do algoritmo de ordenação, incluindo o <b>tempo de execução(time)</b>, o <b>número de comparações(cmp)</b>, o <b>número de movimentos(move)</b> e o <b>número de chamadas de função(calls)</b>.

7. Observações:
Certifique-se de que os arquivos de inclusão e as implementações dos algoritmos de ordenação estejam corretamente configurados antes de compilar e executar o programa.

Para mais informações sobre como usar o programa ou sobre os algoritmos de ordenação implementados, consulte o código-fonte e os comentários fornecidos nos arquivos relevantes.
