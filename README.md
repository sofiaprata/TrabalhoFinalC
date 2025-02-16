# Trabalho Final - Laboratório de Programação (IFCE)

## 🖥 Linguagem: C  
Este projeto realiza a **clusterização de imagens** provenientes de exames de **Papanicolau**, utilizando:  
- O **algoritmo K-means**  
- **Análise de silhueta**  
- Um **leitor de imagens PGM** (Textual P2 ou Binário P5)  

O código segue a organização **linkedizada** para maior modularidade.

---

## 📌 Instruções

### 🔹 1. Preparação
1. Faça o **download da pasta** contendo todas as imagens no formato **PGM**.  
   - Se estiver em outro formato, utilize um programa como **GIMP** para convertê-las para **PGM (P5)**.  

2. **Atualize o caminho da pasta** no arquivo `main.c`.  

### 🔹 2. Compilação
Para compilar o programa, utilize o seguinte comando no terminal:  

```sh
gcc -Wall -Wextra -g3 utilidades.c imagem.c kmeans.c -o output/utilidades.exe
