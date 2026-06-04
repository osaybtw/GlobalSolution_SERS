#include <stdio.h>

int main() {
    float temperatura, energia, geracaoSolar;
    float consumo, comunicacao, saldo;
    int moduloAtivo;

    printf("\n============================\n");
    printf("SISTEMA DE MONITORAMENTO ESPACIAL\n");
    printf("============================\n");

    printf("Temperatura (C): ");
    scanf("%f", &temperatura);

    printf("Energia da bateria (%%): ");
    scanf("%f", &energia);

    printf("Geracao solar (W): ");
    scanf("%f", &geracaoSolar);

    printf("Consumo de energia (W): ");
    scanf("%f", &consumo);

    printf("Qualidade da comunicacao (%%): ");
    scanf("%f", &comunicacao);

    printf("Modulo principal ativo? (1 = Sim, 0 = Nao): ");
    scanf("%d", &moduloAtivo);

    saldo = geracaoSolar - consumo;

    printf("\n============================\n");
    printf("RELATORIO DA MISSAO\n");
    printf("============================\n");

    printf("Temperatura: %.1f C\n", temperatura);
    printf("Energia: %.1f %%\n", energia);
    printf("Geracao solar: %.1f W\n", geracaoSolar);
    printf("Consumo: %.1f W\n", consumo);
    printf("Comunicacao: %.1f %%\n", comunicacao);

    if (moduloAtivo == 1)
        printf("Modulo principal: ATIVO\n");
    else
        printf("Modulo principal: DESLIGADO\n");

    printf("Saldo energetico: %.1f W\n", saldo);

    printf("\nALERTAS\n");

    if (temperatura > 80)
        printf("- Temperatura critica\n");

    if (energia < 20)
        printf("- Energia baixa\n");

    if (comunicacao < 30)
        printf("- Comunicacao instavel\n");

    if (saldo < 0)
        printf("- Consumo maior que a geracao solar\n");

    if (temperatura <= 80 && energia >= 20 &&
        comunicacao >= 30 && saldo >= 0)
        printf("- Nenhum alerta detectado\n");

    printf("\nACOES AUTOMATICAS\n");

    if (energia < 20 || saldo < 0) {
        consumo = consumo * 0.8f;   // reduz 20% do consumo
        printf("- Modo economia ativado\n");
        printf("- Consumo reduzido para %.1f W\n", consumo);
    }

    if (temperatura > 80) {
        temperatura = temperatura - 10.0f; // resfriamento em 10%
        printf("- Sistema de resfriamento ativado\n");
        printf("- Nova temperatura: %.1f C\n", temperatura);
    }

    if (energia < 10 && moduloAtivo == 1) {
        moduloAtivo = 0;
        printf("- Modulo secundario desligado para economizar energia\n");
    }

    saldo = geracaoSolar - consumo;

    printf("\nESTADO APOS AS ACOES\n");
    printf("Temperatura: %.1f C\n", temperatura);
    printf("Consumo: %.1f W\n", consumo);
    printf("Saldo energetico: %.1f W\n", saldo);

    printf("\nSITUACAO GERAL\n");

    if (temperatura > 80 || energia < 20 ||
        comunicacao < 30 || saldo < 0)
        printf("ATENCAO\n");
    else
        printf("ESTAVEL\n");

    return 0;
}