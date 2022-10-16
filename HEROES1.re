booleano dir = verdadeiro
booleano esq = falso
booleano fechar = falso
booleano abrir = verdadeiro
numero estatico temporizador = CarimboMilissegundo()
numero estatico temporizadorsec = 0
numero estatico temporizadorter = 0

tarefa travar com booleano motor
{
TravarMotor ("esqfr",motor)
TravarMotor ("esqat",motor)
TravarMotor ("esqc", motor)
TravarMotor ("dirfr",motor)
TravarMotor ("dirat",motor)
TravarMotor ("dirc", motor)
}
tarefa frente com numero velocidade
{
	travar(falso)
Motor ("esqfr",velocidade)
Motor ("esqat",velocidade)
Motor ("esqc", velocidade)
Motor ("dirfr",velocidade)
Motor ("dirat",velocidade)
Motor ("dirc", velocidade)
}
tarefa parar com numero tempo
{
travar(verdadeiro)
Esperar(tempo)
travar(falso)
}
tarefa esperar com numero tempo
{
Esperar(tempo)
travar(falso)
Pausa(50)
travar(verdadeiro)
}
tarefa tras com numero velocidade
{
	travar(falso)
Motor ("esqfr",0-velocidade)
Motor ("esqat",0-velocidade)
Motor ("dirfr",0-velocidade)
Motor ("dirat",0-velocidade)
Motor ("esqc",0-velocidade)
Motor ("dirc",0-velocidade)
}
tarefa direita com numero velocidade = 1000
{
	travar(falso)
Motor ("esqfr",velocidade)
Motor ("esqat",velocidade)
Motor ("dirfr",0-velocidade)
Motor ("dirat",0-velocidade)
Motor ("esqc",velocidade)
Motor ("dirc",0-velocidade)

}
tarefa esquerda com numero velocidade = 1000
{
	travar(falso)
Motor ("esqfr",0-velocidade)
Motor ("esqat",0-velocidade)
Motor ("dirfr",velocidade)
Motor ("dirat",velocidade)
Motor ("esqc",0-velocidade)
Motor ("dirc",velocidade)

}
############girar##############
tarefa giraresq com numero graus
{
numero angulo = Direcao()
numero forca = 300
se (angulo - graus + 360 > 359) entao {
enquanto (Direcao() > angulo - graus + 3) farei
{

travar(falso)
Esperar(1)
esquerda(forca)
}}
senao  { 				
enquanto (Direcao() < angulo - graus + 359) farei
{         										
travar(falso)
Esperar(1)
esquerda(forca)
}
enquanto (Direcao()> angulo - graus + 359) farei
{
travar(falso)
Esperar(1)
esquerda(forca)
}
}

travar(verdadeiro)
Esperar(200)
travar(falso)
}

####

tarefa girardir com numero graus
{
numero angulo = Direcao()
numero forca = 300
se (angulo + graus - 360 > 0) entao 
{
enquanto (Direcao() > angulo + graus - 360 + 10) farei
	{
Esperar(1)
travar(falso)
direita(forca)
	}
enquanto (Direcao() < angulo + graus - 360) farei
	{

travar(falso)
Esperar(1)
direita(forca)
	}
}

senao 
{ 
enquanto (Direcao() < angulo + graus) farei {
travar(falso)
Esperar(1)
direita(forca)
	}
}
travar(verdadeiro)
Esperar(200)

travar(falso)
}

###################

tarefa avancar (numero forca, numero tempo)
{
frente(forca)
Esperar(tempo)
travar(verdadeiro)
Pausa(100)
travar(falso)
}

#####################

tarefa recuar (numero forca, numero tempo)
{
tras(forca)
Esperar(tempo)
travar(verdadeiro)
Pausa(100)
travar(falso)
}

#######Obstáculo#######

tarefa desviar com booleano destino
{
travar(verdadeiro)
Esperar(500)
travar(falso)
se (destino == esq) entao {

recuar(300,500)
giraresq(90)
avancar(300,1300)
girardir(90)

temporizador = CarimboMilissegundo()
enquanto (Cor("c") != "Preto" e Cor("pesq") != "Preto" e Cor("pdir") != "Preto") farei
{
	
Esperar(1)
frente(300)
se (CarimboMilissegundo() - temporizador >= 4000) entao
{
	girardir(90)
	recuar(200,100)
	temporizador = CarimboMilissegundo()
}
} 
frente(100)
esperar(500)
travar(falso)
giraresq(90)
recuar(300,1500)
}
##
senao
{
recuar(200,800)
girardir(60)
avancar(300,1500)
giraresq(60)
avancar(200,3000)
giraresq(70)
enquanto(Cor("c") != "Preto") farei
{
	frente(150)
	Esperar(1)
}

frente(100)
esperar(800)
enquanto (Cor("c") != "Preto") farei
{
	direita(200)
	Esperar(1)
}
travar(falso)

recuar(300,1500)
}
}
###################



##################

tarefa movergarra (texto motor,numero forca, numero tempo)
{
TravarMotor(motor, falso)
Motor(motor, forca * 0-1)
Esperar(tempo)
TravarMotor(motor, verdadeiro)
}

#################

tarefa pinca (booleano estado)
{
TravarMotor("g1", falso)
TravarMotor("g2", falso)
se (estado == verdadeiro) entao
{
Motor("g2", 200)
Motor("g1", 200)

Esperar(800)
}
se (estado == falso) entao
{
Motor("g1", 0-200)
Motor("g2", 0-200)

Esperar(800)
}
TravarMotor("g1", verdadeiro)
TravarMotor("g2", verdadeiro)
}

##################



#################
numero estatico res = 0
tarefa resg 
{

LimparConsole()

se (Ultra("ultraesq") < 5 e Ultra("ultraesq") > 0) entao
{
	se (res < 1) entao
	{
enquanto (Ultra("resgate") > 6 ou Ultra("resgate") < 0 ou Cor("fr") != "Preto") farei
{
Esperar(1)
Escrever("procurando")
frente(300)
se (Ultra("ultrafr") < 3 e Ultra("ultrafr") > 0) entao
{
	
parar(1000)
recuar(200,1000)
LimparConsole()
avancar(200,1000)
travar(verdadeiro)
Esperar(500)
girardir(86)
travar(falso)
recuar(400,1000)
}
se (CorAzul("c") + 40 < CorVerde("c")) entao
{
	parar(1000)
	recuar(300,1800)
	travar(verdadeiro)
	Esperar(500)
	girardir(86)
	recuar(500,1000)
	travar(falso)
}
}
parar(2000)
LimparConsole()
Escrever("concluido")




travar(falso)
enquanto ((Toque("dtoq") == falso e Toque("etoq") == falso) e (TemAlgo("ultraesq") == verdadeiro ou TemAlgo("ultradir") == verdadeiro)) farei
{
Escrever("preparando")
Esperar(1)
tras(300)
}	se(TemAlgo("ultraesq") == falso e TemAlgo("ultradir") == falso) entao
{
enquanto(TemAlgo("ultraesq") == falso e TemAlgo("ultradir") == falso) farei
{
	Esperar(1)
	frente(400)
}
avancar(200,3000)
}
senao
{
	avancar(200,500)
}
parar(1000)
girardir(80)
recuar(500,2000)
se(TemAlgo("ultradir") == verdadeiro e TemAlgo("ultraesq") == verdadeiro) entao
{
	enquanto(TemAlgo("ultradir") == verdadeiro) farei
	{
		Esperar(1)
		frente(200)
	}
}
#primeiro movimento#

Escrever("primeiro movimento")

temporizador = CarimboMilissegundo()
avancar(200,2000)
enquanto((Ultra("ultrafr") > 8 ou Ultra("ultrafr") < 6) e Cor("c") != "Preto") farei
{
	Esperar(1)
	Escrever(VirarTexto(CarimboMilissegundo() - temporizador))
	frente(200)
}
se(Cor("c") == "Preto") entao
{
	parar(500)

	recuar(300,4000)
	

}
numero girando = 0
numero avancando = 0
se (CarimboMilissegundo() - temporizador < 10000) entao
{
	girando = 40
	avancando = 10000
	parar(1000)
	giraresq(90)
	recuar(500,1000)
	avancar(200,6000)
}
senao
{
	avancando = 13000
	girando = 130
	parar(1000)
recuar(200,2000)
}



giraresq(girando)
travar(verdadeiro)

TravarMotor("lev",falso)
	Motor("lev", 900)
	Esperar(1000)
	TravarMotor("lev",verdadeiro)
pinca(abrir)
travar(falso)
avancar(150,avancando)
travar(falso)

pinca (fechar)
travar(verdadeiro)
Esperar(50)
travar(falso)


TravarMotor("lev",falso)
	Motor("lev", 0-100)
	Esperar(900)
	TravarMotor("lev",verdadeiro)
travar(falso)
avancar(300,2000)

travar(verdadeiro)
TravarMotor("lev",falso)
	Motor("lev", 400)
	Esperar(1000)
	TravarMotor("lev",verdadeiro)
pinca(abrir)
travar(falso)
TravarMotor("lev",falso)
	Motor("lev", 0-300)
	Esperar(500)
	TravarMotor("lev",verdadeiro)
parar(1000)
pinca(fechar)
travar(verdadeiro)
TravarMotor("lev",falso)
	Motor("lev", 0-1000)
	Esperar(2000)
	TravarMotor("lev",verdadeiro)

avancar(300,2500)
res = 1
##


}
senao
{
	avancar(300,1000)
	girardir(90)

	avancar(400,1000)
	enquanto(TemAlgo("ultradir") == verdadeiro e CorAzul("c") + 40 > CorVerde("c")) farei
	{
		frente(200)
		se(Ultra("ultrafr") < 3 e TemAlgo("ultrafr") == verdadeiro) entao
		{
			giraresq(90)
			recuar(500,2000)
		
		}
	}
	se (TemAlgo("ultradir") == falso) entao
	{
		girardir(90)
		temporizador = CarimboMilissegundo()
		enquanto (CarimboMilissegundo() - temporizador < 4000 e CorAzul("c") + 40 > CorVerde("c")) farei
		{
			Esperar(1)
			frente(200)

		}
		se (CorAzul("c") + 40 < CorVerde("c")) entao
		{
			avancar(300,800)
			temporizador = CarimboMilissegundo()
			enquanto (Cor("cdir") != "Preto" e CarimboMilissegundo() - temporizador < 3000) farei
			{
				Esperar(1)
				esquerda(200)
			}
			se(CarimboMilissegundo() - temporizador >= 3000) entao
			{
				recuar(300,500)
				enquanto (Cor("cesq") != "Preto") farei
				{
					Esperar(1)
					direita(200)
				}
			}


		}
		
	}
}	
}
}

#####################


inicio

LimparConsole()

AbrirConsole()
pinca(fechar)
TravarMotor("lev", falso)
Motor("lev",0-1000)
Esperar(1000)
TravarMotor("lev",verdadeiro)
travar(falso)

enquanto (verdadeiro) farei {
	
	travar(falso)
    Esperar(1)
	
	
    frente(180)

    ##
#intersecção#
    se (Cor("pdir")== "Preto" e Cor("pesq")== "Preto") entao
    {
		se (((CorVerde("cdir") - 20 > CorAzul("cdir") ou CorVerde("pdir") - 20 > CorAzul("pdir") ) e ((CorVerde("c") - 20 > CorAzul("c")) ou (CorVerde("cesq") - 20 > CorAzul("cesq") ou CorVerde("pesq") - 20 > CorAzul("pesq")))) ou (CorVerde("cesq") - 20 > CorAzul("cesq") ou CorVerde("pesq") - 20 > CorAzul("pesq") ) e ((CorVerde("c") - 20 > CorAzul("c")) ou (CorVerde("cdir") - 20 > CorAzul("cdir") ou CorVerde("pdir") - 20 > CorAzul("pdir")))) entao
	{
	Escrever("beco")
	recuar(300,300)
	girardir(180)
	
	
    avancar(100,100)
	}
	senao
	{
    EscreverLinha("intersecção")
    avancar(300,1000)
	se (TemAlgo("ultrafr") == verdadeiro e TemAlgo("ultraesq") == verdadeiro) entao
	{	
		
			 Escrever("caso 1")
			resg()
		}
		senao{
			recuar(200,400)
		}
	}
    LimparConsole()
	}
	
#esquerda#
	se (Cor("cdir")=="Branco" e Cor("cesq") == "Preto") entao
	{
		Escrever("esquerda")
	esquerda(300)
	}

	##

	se (Cor("pdir")=="Branco" e Luz("pesq") <= 30 e Cor("cesq")=="Branco") entao
	{
		Escrever("esquerda longa")
	parar(300)
	avancar(300,200)
	giraresq(30)
	recuar(400,100)
	}
#direita#
	se (Cor("cdir") == "Preto" e Cor("cesq")=="Branco") entao
	{
		Escrever("direita")
	direita(300)
	}

	##
	se (Cor("pesq")=="Branco" e Luz("pdir") <= 30 e Cor("cdir")=="Branco") entao
	{
		Escrever("direita longa")
	parar(300)
	avancar(300,200)
	girardir(40)
	recuar(400,100)
	}
#	#
#90 direita#
	se (Cor("pdir")=="Preto" e Cor("cdir")=="Preto" e Cor("pesq")=="Branco") entao
	{
        Escrever("90 direita")
	parar(600)
	
	
	avancar(200,800)
	parar(400)

se(TemAlgo("ultradir") == verdadeiro e Ultra("ultrafr") < 30 e Ultra("ultradir") < 4 e Ultra("ultraesq") > 26 ) entao
{
	 Escrever("caso dir")
	resg()
}
senao{
	enquanto(Cor("cesq")!="Preto" e Cor("c")!="Preto") farei
	{
	
    Esperar(1)
    direita(300)
	}
	parar(500)
	
	LimparConsole()
	}}
	
#90 esquerda#
	se (Cor("cesq")=="Preto" e Cor("pesq")=="Preto" e Cor("cdir")=="Branco") entao
	{
    Escrever("90 esquerda")
	parar(600)

	avancar(200,800)
	parar(400)
	se(TemAlgo("ultradir") == verdadeiro e Ultra("ultrafr") < 30 e Ultra("ultradir") < 4 e Ultra("ultraesq") > 26 ) entao
{
	
	resg()
}
senao{
	
	enquanto(Cor("cdir")!="Preto" e Cor("c")!="Preto") farei
	{
	
    Esperar(1)
    esquerda(300)

	}
	parar(500)
	
	LimparConsole()
		}}
		
	
	
	
	
#Obstaculo#
	se (Ultra("ultrafr")>1 e Ultra("ultrafr")<=2) entao
	{
	se (Ultra("resgate") > Ultra("ultrafr")) entao
	{
	Escrever("Obstaculo")
	desviar(dir)
	LimparConsole()
	}}
#verde esquerda#
	se ((Cor("cesq") == "Preto" e CorVerde("cesq") - 40 > CorAzul("cesq") e CorVerde("cesq") - 60 > CorVermelho("cesq") e Cor("cdir") != "Preto") ou (Cor("cesq") =="Verde") ou (Cor("pesq") == "Preto" e CorVerde("pesq") - 40 > CorAzul("pesq") e CorVerde("pesq") - 60 > CorVermelho("pesq") e Cor("pdir") != "Preto") ou (Cor("pesq") =="Verde" ou Cor("pesq") == "Ciano")) entao
	{
	Escrever(Cor("cesq"))
	parar(500)
    recuar(200,400)
	giraresq(5)
temporizador = CarimboMilissegundo()
    enquanto((CorVerde("cdir") - 20 < CorAzul("cdir") e CorVerde("pdir") - 20 < CorAzul("pdir")) e CarimboMilissegundo() - temporizador < 2000) farei
	{
        Esperar(1)
        frente(100)

    }
    se (CarimboMilissegundo() - temporizador < 3000) entao
    {
	se ((Cor("cesq") == "Preto" e CorVerde("cesq") - 40 > CorAzul("cesq") e CorVerde("cesq") - 60 > CorVermelho("cesq") e Cor("cdir") != "Preto") ou (Cor("cesq") =="Verde") ou (Cor("pesq") == "Preto" e CorVerde("pesq") - 40 > CorAzul("pesq") e CorVerde("pesq") - 60 > CorVermelho("pesq") e Cor("pdir") != "Preto") ou (Cor("pesq") =="Verde" ou Cor("pesq") == "Ciano")) entao {
	giraresq(5)
	se (((CorVerde("cdir") - 20 > CorAzul("cdir") ou CorVerde("pdir") - 20 > CorAzul("pdir") ) e ((CorVerde("c") - 20 > CorAzul("c")) ou (CorVerde("cesq") - 20 > CorAzul("cesq") ou CorVerde("pesq") - 20 > CorAzul("pesq")))) ou (CorVerde("cesq") - 20 > CorAzul("cesq") ou CorVerde("pesq") - 20 > CorAzul("pesq") ) e ((CorVerde("c") - 20 > CorAzul("c")) ou (CorVerde("cdir") - 20 > CorAzul("cdir") ou CorVerde("pdir") - 20 > CorAzul("pdir")))) entao
	{
	Escrever("beco")
	
	girardir(180)
	
	avancar(100,500)
	}
	senao
	{
	avancar(200,200)
	esquerda(200)
	esperar(500)	
	
		
	avancar(200,800)
	
	enquanto (Cor("c") != "Preto") farei
	{
		Esperar(1)
		esquerda(200)
	}
	avancar(300,200)
	LimparConsole()
	}
	}
	 
	
	 
	senao 
	{
		recuar(300,500)
	}
	}}
#verde direita#
	se ((Cor("cdir") == "Preto" e CorVerde("cdir") - 40 > CorAzul("cdir") e CorVerde("cdir") - 60 > CorVermelho("cdir") e Cor("cesq") != "Preto") ou (Cor("cdir") == "Verde") ou (Cor("pdir") == "Preto" e CorVerde("pdir") - 40 > CorAzul("pdir") e CorVerde("pdir") - 60 > CorVermelho("pdir") e Cor("pesq") != "Preto") ou (Cor("pdir") == "Verde")) entao
	{
	Escrever(Cor("cesq"))
	parar(500)
	
	recuar(200,400)
	giraresq(5)
temporizador = CarimboMilissegundo()
    enquanto((CorVerde("cdir") - 20 < CorAzul("cdir") e CorVerde("pdir") - 20 < CorAzul("pdir")) e CarimboMilissegundo() - temporizador < 2000) farei
	{
        Esperar(1)
        frente(100)

    }
    se (CarimboMilissegundo() - temporizador < 3000) entao
    {
		
	se ((Cor("cdir") == "Preto" e CorVerde("cdir") - 40 > CorAzul("cdir") e CorVerde("cdir") - 60 > CorVermelho("cdir") e Cor("cesq") != "Preto") ou (Cor("cdir") == "Verde") ou (Cor("pdir") == "Preto" e CorVerde("pdir") - 40 > CorAzul("pdir") e CorVerde("pdir") - 60 > CorVermelho("pdir") e Cor("pesq") != "Preto") ou (Cor("pdir") == "Verde")) entao {
	girardir(5)

	se (((CorVerde("cdir") - 20 > CorAzul("cdir") ou CorVerde("pdir") - 20 > CorAzul("pdir") ) e ((CorVerde("c") - 20 > CorAzul("c")) ou (CorVerde("cesq") - 20 > CorAzul("cesq") ou CorVerde("pesq") - 20 > CorAzul("pesq")))) ou (CorVerde("cesq") - 20 > CorAzul("cesq") ou CorVerde("pesq") - 20 > CorAzul("pesq") ) e ((CorVerde("c") - 20 > CorAzul("c")) ou (CorVerde("cdir") - 20 > CorAzul("cdir") ou CorVerde("pdir") - 20 > CorAzul("pdir")))) entao
	{
	Escrever("beco")
	
	girardir(180)
	
	avancar(100,500)
	}
	senao{
	avancar(200,200)
	direita(200)
	esperar(500)
	
		
	avancar(200,800)
	
	enquanto (Cor("c") != "Preto") farei
	{
		Esperar(1)
		direita(200)
	}
	}
	}
	senao 
	{
		recuar(300,500)
	}
	LimparConsole()
	}}
	####
#beco sem saida#
	se (((CorVerde("cdir") - 20 > CorAzul("cdir") ou CorVerde("pdir") - 20 > CorAzul("pdir") ) e ((CorVerde("c") - 20 > CorAzul("c")) ou (CorVerde("cesq") - 20 > CorAzul("cesq") ou CorVerde("pesq") - 20 > CorAzul("pesq")))) ou (CorVerde("cesq") - 20 > CorAzul("cesq") ou CorVerde("pesq") - 20 > CorAzul("pesq") ) e ((CorVerde("c") - 20 > CorAzul("c")) ou (CorVerde("cdir") - 20 > CorAzul("cdir") ou CorVerde("pdir") - 20 > CorAzul("pdir")))) entao
	{
	Escrever("beco")
	
	girardir(180)
	
	avancar(100,500)
	}
##

##

#area de resgate#
	se (Ultra("ultrafr") > 10 e Ultra("ultraesq") > 0 ) entao
	{   girardir(10)
		se (Ultra("ultrafr") > 10 e Ultra("ultraesq") > 0 ) entao
	{
		 Escrever("caso principal")
	resg()
	}
	}


#fim#
	se(Cor("c") == "Vermelho") entao{
	parar(1000000)
	}
}
fim