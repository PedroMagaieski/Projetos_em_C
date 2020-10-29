#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<dirent.h>

/*Exercício: fazer um programa em "C" que solicita o total gasto pelo cliente de uma loja,
 imprime as opções de pagamento, solicita a opção desejada e imprime o valor total das prestações (se houverem)
 1) Opção: a vista com 10% de desconto
 2) Opção: em duas vezes (preço da etiqueta)
 3) Opção: de 3 até 10 vezes com 3% de juros ao mês (somente para compras acima de R$ 100,00). */

int main(){
    int opcao;
    float gastos,pagamento=0,parcelas,juros,prest,total;
    
    printf("\nDigite o total gasto em nossa loja: \n");
    scanf("%f",&gastos);
    if(gastos>=100){
            opcao = 3;
            printf("\nDigite o numero de parcelas (de 3 ate 10 vezes): \n");
            scanf("%f",&parcelas);
    }else{
        printf("\nDigite o numero relativo a forma de pagamento: \n1- a vista com 10 por cento de desconto\n2-em duas vezes (preco da etiqueta)\n");
        scanf("%d",&opcao);
    }
    switch (opcao){
        case 1:
            pagamento = gastos-(gastos * 0.1);
            printf("\nO valor a vista eh: %.2f \n",pagamento);
        break;
        case 2:
            pagamento=gastos/2;
            printf("\nO valor das prestacoes eh: %.2f\n",pagamento);
        break;
        case 3:
            prest = (gastos/parcelas);
            printf("\n[O valor das prestacoes eh: %.2f] \n",prest);
            printf("\n-------------------------------\n");
            juros = prest * 0.03;
            for(int i=0;i<parcelas;i++){
                pagamento = prest += juros;
                printf("\nO valor dos juros eh: %.2f \n",juros);
                printf("\nO valor das prestacoes somadas aos juros eh: %.2f \n",pagamento);
                printf("\n-------------------------------\n"); 
            }      
        break;
    }
}