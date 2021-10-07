# Epi-R
Epi-R é uma bilioteca de funções e interface gráfica para análise de dados epidemiologicos em R.

O Epi-R também é uma ferramenta que pode ser usada em cursos introdutórios de Bioestatística.

Este aplicativo é desenvolvido pelo Instituto de Medicina Social da Universidade do Estado do Rio de Janeiro com finaciamento do Ministério da Saúde do Brasil.

O Epi-R é desenvolvido totalmente em R e a interface gráfica em GTk2.


## Instalação

Para instalar o R no Windows acesse este [link](https://cloud.r-project.org/).

### Windows



### Linux

Estas instruções são para o Ubuntu 20.04 e outras distribuições derivadas.

Antes de instalar o Epi-R no Linux é necessário instalar os arquivos de desenvolvimento das bibliotecas utilizadas pelos pacotes do R. Certifique-se que o pacote r-base-dev esteja instalado.

No terminal do Linux, execute os seguiinte comando
```r
sudo apt install r-base-dev libmysqlclient-dev libcurl4-openssl-dev libxml2-dev unixodbc-dev libcairo2-dev libxt-dev libgtk2.0-dev

```

### MacOS

Este programa não foi testado no sistema operacional Mac OS.


### Etapas comuns

Instale as dependẽncias

```r
install.packages(c("boot","bitops","caTools","RGtk2","cairoDevice","foreign","lattice","DBI","RODBC","RSQLite","zoo","lmtest","akima","gam","gtools","gdata","gplots"), dep=TRUE)
```
e instale o Epi-R
```r
install.packages("remotes")
remotes::install_github("wjunger/EpiR")
library(EpiR)
```

ou

```r
install.packages("remotes")
remotes::install_github("NPEA/EpiR")
library(EpiR)
```

No Windows, ao executar o EpiR pela primeira vez, clique em "sim" para instalar a bilbioteca GTk2.


Acesse a [página do pacote remotes](https://github.com/r-lib/remotes) para mais informações sobre como instalar pacotes do GitHub no R.


## Licença
Este software é distribuído sob a licensa GPL 2 ou superior.

Epi-R é um software livre e vem sem GARANTIA ALGUMA.
Você pode redistribuí-lo sob certas circunstâncias.
