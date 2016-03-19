#include <cstdio>

int main() {
	int alunos, folhas, cada;
	scanf(" %d %d %d", &alunos, &folhas, &cada);
	printf("%s\n", alunos*cada<=folhas?"S":"N");
	return 0;
}
