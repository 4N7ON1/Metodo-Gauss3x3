#include <stdio.h>
#include <stdlib.h>

#define F 3 //F es el número de filas.
#define C 4 //C es el número de columnas.

void ingresarValores(double[][C]);
void mostrarSistema(double[][C]);
void editarValores(double[][C]);
int verificarSistema(double[][C]);
void intercambiarFilas(double[][C]);
void resolverSistema(double[][C]);

int main(void)
{
	system("title SISTEMA DE ECUACIONES MÉTODO DE GAUSS 3x3");	//Título en la consola.

	short int editar, salir = 0;
	
	do
	{
		system("cls");
		double m[F][C] = {0};
		
		ingresarValores(m); //Módulo para ingresar los valores.
		
		do
		{
			system("cls");
			
			printf("\n\n\t\t\t    TU SISTEMA DE ECUACIONES ES EL SIGUIENTE\n");
			mostrarSistema(m); //Módulo para mostrar el sistema de ecuaciones.
			
			printf("\n\n\n\t\t\t    0. Resolver sistema de ecuaciones.");
			printf("\n\n\t\t\t    1. Editar valores del sistema de ecuaciones.");
			printf("\n\n\n\t\t\t    Ingresa la opci%cn correspondiente: ",162);
			scanf("%d",&editar);
			
			if(editar)
				editarValores(m);
		
		}while(editar);
		
		while(!verificarSistema(m)) //Verifica que el sistema de ecuaciones sea de 3x3.
		{
			system("pause>nul");
			editarValores(m); //En caso de no serlo, editar valores.
		}
		
		system("cls");
		printf("\n\n\n\t\t\t    TU SISTEMA DE ECUACIONES ES EL SIGUIENTE\n");
		intercambiarFilas(m); //En caso que coeficiente de X fila 1 sea 0, intercambia la fila.
		
		printf("\n\n\n\n\t\t\t\t\tPROCEDIMIENTO");
		resolverSistema(m);//Módulo para resolver las ecuaciones.
		
		printf("\n\n\n\n\t\t\t\t\t\t0. Salir");
		printf("\n\n\t\t\t\t1. Ingresar nuevo sistema de ecuaciones 3x3.");
		printf("\n\n\n\n\t\t\t\t    Ingrese la opci%cn correspondiente: ",162);
		scanf("%d",&salir);
		
	}while(salir);
	
	return 0;
}

void ingresarValores(double m[][C])
{
	short int i, j; 
	char valorCadena[10];
	double valor;
	
	for(i=0; i<F; i++)
		for(j=0; j<C; j++)
		{
			do
			{
				setbuf(stdin,NULL);
				
				printf("\n\n\t\t\t\t    INGRESA LOS VALORES\n");
				mostrarSistema(m);
				
				if(!j) //Para ingresar los coeficientes de X.
					printf("\n\n\n\t\t\t  Ingresa el coeficiente de X de la fila %d: ",i+1);
				
				else if(j==1) //Para ingresar los coeficientes de Y
					printf("\n\n\n\t\t\t  Ingresa el coeficiente de Y de la fila %d: ",i+1);
					
				else if(j==2) //Para ingresar los coeficientes de Z.
					printf("\n\n\n\t\t\t  Ingresa el coeficiente de Z de la fila %d: ",i+1);
		
				else printf("\n\n\n\t\t\t  Ingresa el t%crmino independiente fila %2d: ",130,i+1);
		
				scanf("%10[^\n]s",valorCadena); //Valor se guarda en cadena.
				valor = atof(valorCadena); //Convertir la cadena a tipo double.
				
				system("cls"); //Limpiar pantalla
			
			}while(!valor && valorCadena[0] != 48 ); //Valida que sólo se ingresen números.
			
			m[i][j] = valor; //Guarda el valor convertido en la matriz.
		}
}


void mostrarSistema(double m[][C])
{
	int i, j;
		
	for(i=0; i<F; i++)
	{
		printf("\n\n\t");
		for(j=0; j<C; j++)
		{
			if(!j) //Muestra los coeficientes de X 
				printf("\t%10.2lf x ",m[i][j]);
				
			else if(j==1) //Muestra los coeficientes de Y.
			{
				if(m[i][j]<0) //Si el coeficiente de Y es menor a 0, lo muestra negativo.
					printf("  -%10.2lf y ",-1*m[i][j]);
					
				else printf("  +%10.2lf y ",m[i][j]); //De lo contrario lo muestra positivo.
			}
			
			else if(j==2)
			{
				if(m[i][j]<0) //Si el coeficiente de z es menor a 0, lo muestra negativo.
					printf("  -%10.2lf z ",-1*m[i][j]);
					
				else printf("  +%10.2lf z ",m[i][j]); //De lo contrario lo muestra positivo.	
			}
			
			else printf("  =%10.2lf",m[i][j]); //Muestra los valores de los términos independientes.
		}
	}
}

void editarValores(double m[][C])
{
	short int f, c; //"f" se guarda la fila y "c" guarda la columna.
	double valor; //Para guardar el nuevo valor a cambiar.
	char var, valorCadena[10];//"var" para guardar la variable y "valorCadena" para convertirlo a atof.
	
	do //Bucle para que validar que ingrese sólo el rango del número de filas.
	{
		system("cls");
		setbuf(stdin,NULL);
	
		printf("\n\n\t\t\t\tEDITANDO SISTEMA DE ECUACIONES\n");
		mostrarSistema(m); //Módulo para mostrar el sistema de ecuaciones
		
		printf("\n\n\n\t\t\t    Ingresa el n%cmero de fila a editar: ",163);
		scanf("%d",&f);
		
		if(f<1 || f>3)
		{
			printf("\n\t\t\t\t     Esa fila no existe.");
			system("pause>nul");
		}
		
	}while(f<1 || f>3);
	
	do //Bucle para validar que sólo ingrese el rango del número de columnas.
	{
		system("cls");
		setbuf(stdin,NULL);
	
		printf("\n\n\t\t\t\tEDITANDO SISTEMA DE ECUACIONES\n");
		mostrarSistema(m); //Módulo para mostrar el sistema de ecuaciones
		
		printf("\n\n\n\t   Variables: \"x\",  \"y\",");
		printf("  \"z\"  o  \"t\" (t es la columna de t%crminos independientes)",130);
		printf("\n\n\t\t  Ingresa la variable del coeficiente de la fila %d a editar: ",f);
		scanf("%c",&var);
		
		if(var<90) //Verifica si se ingresa en mayúsculas.
			var += 32; //En caso de ingresarse en mayúsculas, lo convierte a minúsculas
		
		if(var != 'x' && var != 'y' && var != 'z' && var != 't')
		{
			printf("\n\n\t\t\tEsa variable no se encuentra en el sistema.");
			system("pause>nul");
		}
			
	}while(var != 'x' && var != 'y' && var != 'z' && var != 't');
	
	if(var == 'x')
		c = 0;

	else if(var == 'y')
		c = 1;
	
	else if(var == 'z')
		c = 2;

	else c = 3;
	
	do
	{
		setbuf(stdin,NULL);
		system("cls");
		
		printf("\n\n\n\t\t\t");
		
		if(var == 'x')
			printf("El valor actual del coeficiente \"X\" de la fila %d es: %.2lf",f,m[f-1][c]);
					
		else if(var == 'y')
			printf("El valor actual del coeficiente \"Y\" de la fila %d es: %.2lf",f,m[f-1][c]);
			
		else if(var == 'z')
			printf("El valor actual del coeficiente \"Z\" de la fila %d es: %.2lf",f,m[f-1][c]);
		
		else
		{
			printf("El valor actual del t%crmino independiente",130);
			printf(" de la fila %d es: %.2lf",f,m[f-1][c]);
		}

		
		printf("\n\n\t\t\t\tIngresa el nuevo valor a sustituir: ");
		scanf("%10[^\n]s",valorCadena); //Valor se guarda en cadena.
		valor = atof(valorCadena); //Convertir la cadena a tipo double.
		
		//system("cls"); //Limpiar pantalla
	
	}while(!valor && valorCadena[0] != 48 ); //Valida que sólo se ingresen números.
	
	m[f-1][c] = valor; //Guarda el valor nuevo en la posición correspondiente.
}


int verificarSistema(double m[][C])
{
	//variables x, y & z para contar contabilizar los coeficientes de ingresados, variable "sistema"
	short int i, x =3, y = 3, z = 3, sistema = 1; //se asume verdadero y que el sistema es 3x3. 
	
	for(i=0; i<F; i++) //Ciclo para comprobar que el sistema de ecuaciones sea de 3x3.
	{
		if(!m[i][0]) //Cada que el coeficiente de la variable "x" sea 0, se sustrae 1 a variable x.
			x--;
			
		if(!m[i][1])//Cada que el coeficiente de la variable "y" sea 0, se sustrae 1 a variable y.
			y--;
		
		if(!m[i][2])//Cada que el coeficiente de la variable "z" sea 0, se sustrae 1 a variable z.
			z--;
	}	
	
	if(!x || !y || !z)
	{
		sistema = 0; //En caso que los 3 coeficientes de una variable sean 0, entonces no es 3x3.
		printf("\n\n\n\t\t\tAl parecer tu sistema de ecuaciones no es de 3x3.");
		
		if(!x)
			printf("\n\n\t\t\t  Los 3 coeficientes de la variable \"x\" son 0.");
		
		if(!y)
			printf("\n\n\t\t\t  Los 3 coeficientes de la variable \"y\" son 0.");
			
		if(!z)
			printf("\n\n\t\t\t  Los 3 coeficientes de la variable \"z\" son 0.");
	}	
	
	return sistema;
}

void intercambiarFilas(double m[][C])
{
	short int i, fila = 0; //Fila toma valor de 0 porque se asume que no se permutarán las filas.
	double v[C] = {0}; //Vector auxiliar.
	
	mostrarSistema(m); //Mostrar el sistema ingresado por el usuario.
	
	if(!m[0][0]) //Verifica si el coeficiente de "x" de la fila 1 es cero.
		for(i=0; i<C; i++) 
			v[i] = m[0][i]; //Guardar los elementos de la primera ecuación a vector auxiliar.	

	if(!m[0][0] && m[1][0]) //En caso de que el coeficiente de "x" de la fila 1 sea 0 y el coeficiente
		for(i=0; i<C; i++) //coeficiente de "x" de fila 2 sea diferente de 0, se permutan valores.
		{
			m[0][i] = m[1][i]; //Guarda los valores de la fila 2 en la fila 1.
			m[1][i] = v[i]; //Guarda el valor de la fila 1 en la fila 2.
			fila = 2; //Fila toma el valor de 2 porque es la fila que se permuta con fila 1.
		}
		
	else if(!m[0][0] && m[2][0]) //De lo contrario, los valores de la ecuación 1 se permutan con los
		for(i=0; i<C; i++) //valores de la fila 3.
		{
			m[0][i] = m[2][i];
			m[2][i] = v[i];
			fila = 3;
		}
		
	if(fila) //Si se permutan filas, se muestra el siguiente mensaje.
	{
		printf("\n\n\n\t\t\t\tSe permuta la fila 1 con la fila %d.\n",fila);
		mostrarSistema(m);
	}
}


void resolverSistema(double m[][C])
{
	short int i, negativoFila3 = 0;
	double v1[C] = {0}, v2[C] = {0}, x, y, z; //Vectores aux, & variables para guardar su valor.
	char homogenea = 'f', determinado = 0; //Se asume que el sistema NO será homogeneo.

	if(!m[0][3] && !m[1][3] && !m[2][3]) //Verifica si el sistema es homogeneo.
		homogenea = 'v'; //Guardar "v" de verdadero en caso de serlo así.
	
	if(m[1][0]) //Verifica si el coeficiente de x de la fila 2 sea diferente de 0.
	{
		printf("\n\n\n");
		//printf("\n\n\n\tSe multiplica por %.2lf a la fila 1 y por %.2lf a la fila 2",-1*m[1][0],m[0][0]);
		//printf(", se suman y se guarda en fila 2.\n");
		
		for(i=0; i<C; i++) //Bucle para multiplicar la ecuación 1 por el coeficiente de x de la fila 2
		{ 				//y para multiplicar la ecuación 2 por el coeficiente de x de la fila 1.
			v1[i] = (-1 * m[1][0]) * m[0][i]; //Ec. 1 se multiplica por opuesto del coef. de x fila 2.
			v2[i] = m[0][0] * m[1][i]; //Ec. 2 se multiplica por el coeficiente de x fila 1.
		}
		
		for(i=0; i<C; i++)
			m[1][i] = v1[i] + v2[i]; //Se hace la suma y se guarda en fila 2.
		
		mostrarSistema(m);
	}
	
	if(m[2][0]) //Verifica si el coeficiente de x de la fila 2 sea diferente de 0.
	{
		//printf("\n\n\n\tSe multiplica por %.2lf a la fila 1 y por %.2lf a la fila 3",-1*m[2][0],m[0][0]);
		//printf(", se suman y se guarda en fila 3.\n");
		printf("\n\n\n\n");
		for(i=0; i<C; i++) //Bucle para multiplicar la ecuación 1 por el coeficiente de x de la fila 2
		{ 				//y para multiplicar la ecuación 2 por el coeficiente de x de la fila 1.
			v1[i] = (-1 * m[2][0]) * m[0][i]; //Ec. 1 se multiplica por opuesto del coef. de x fila 3.
			v2[i] = m[0][0] * m[2][i]; //Ec. 3 se multiplica por el coeficiente de x fila 1.
		}
		
		for(i=0; i<C; i++)
			m[2][i] = v1[i] + v2[i]; //Se hace la suma y se guarda en fila 3.

		mostrarSistema(m);
	}
	
	if(m[2][1]) //Verifica si el coeficiente de la fila 3 de la variable y sea diferente de 0.
	{
		printf("\n\n\n\tSe multiplica por %.2lf a la fila 2 y por %.2lf a la fila 3",m[2][1],-1*m[1][1]);
		printf(", se suman y se guarda en fila 3.\n");
	
		if(m[2][1]<0) //En caso que el coeficiente de la fila 3 de la variable y sea negativo.
			negativoFila3++; //Servirá para multiplicar la fila 3 por (-1).
			
		for(i=1; i<C; i++) //Bucle para multiplicar la ecuación 1 por el coeficiente de x de la fila 2
		{ 				//y para multiplicar la ecuación 2 por el coeficiente de x de la fila 1.
			v1[i] = (-1 * m[2][1]) * m[1][i]; //Ec. 2 se multiplica por opuesto del coef. de y fila 3.
			v2[i] = m[1][1] * m[2][i]; //Ec. 3 se multiplica por el coeficiente de y fila 2.
		}
		
		for(i=1; i<C; i++)
			m[2][i] = v1[i] + v2[i]; //Se hace la suma y se guarda en fila 3.
		
		if(m[1][1]<0) //Condición para validar cuál era el valor que se tenía que cambiar de signo.
			for(i=2; i<C; i++)//En caso de que el coeficiente del la variable "y" sea negativo,
				m[2][i] *= -1;//entonces basta con cambiar de signo a la fila 3.
		
		if(negativoFila3 && m[1][1]<0) //Si coef. de variable "y" resultó negativo y coef. de variable
			for(i=2; i<C; i++)// "y" de la segunda fila también lo es, entonces multiplicar ecuación 3
				m[2][i] *= -1;//por (-1).
	}
	
	printf("\n\n\t\t\t\tSe obtiene matriz triangular superior.\n");
	mostrarSistema(m);	
	
	printf("\n\n\n\t\t\t\t      Valores de las inc%cgnitas",162);

	if(!m[2][0] && !m[2][1] && !m[2][2])//Verifica si es sistema homogeneo determinado (solucion 0)
			determinado++; //o si es un sistema homogeneo indeterminado (infinitas soluciones)
		
	if(homogenea == 'v' && !determinado)
	{
		printf("\n\n\n\t\t\t\t\t\tX = 0");
		printf("\n\n\t\t\t\t\t\tY = 0");
		printf("\n\n\t\t\t\t\t\tY = 0");		

		printf("\n\n\n\t\t\tEs un sistema lineal homog%cneo determinado (soluci%cn trivial).",130,162);
	}
		
	else if(homogenea == 'v' && determinado)
	{
		y = ( -1 * m[1][2] ) / m[1][1];
		x =	( -1 * m[0][2] + ( -1 * m[0][1] * (-1 * m[1][2] / m[1][1]))) / m[0][0];
		
		printf("\n\n\n\t\t\t\t\t    X = %4.10lf w",x);
		printf("\n\n\n\t\t\t\t\t    Y = %4.10lf w",y);
		printf("\n\n\n\t\t\t\t\t    Z =  w");

		printf("\n\n\n\t\t\tEs un sistema lineal homog%cneo indeterminado (infinitas soluciones).",130);		
		printf("\n\n\n\t\t\tDonde \"w\" puede ser cualquier valor y siempre ser%c soluci%cn.",160,162);
	}
	
	else if(determinado && (m[2][2] != m[2][3] ) )
		printf("\n\n\n\n\t\t\t  NO existe soluci%cn para este sistema lineal no homog%cneo.",162,130);

	else if(determinado) //Infinitas soluciones, muestra ecuaciones con el parámero "w"
	{
		
	/*	if(m[0][2]<0)
			printf("\n\n\t\t\t\t\tX = [ ( %3.2lf + %3.2lf w)",m[0][3],-1*m[0][2]);
		
		else printf("\n\n\t\t\t\tX = [ ( %3.2lf - %3.2lf w)",m[0][3],m[0][2]);
		
		if(m[1][2]<0)
			printf(" + (%3.2lf",m[1][3] / m[1][1]);
		
		else printf(" - (%3.2lf",-1*m[1][3] / m[1][1]);
		
		if(m[1][2]<0)
			printf(" + %3.2lf w) ]",-1*m[1][2] / m[1][1]);
		
		else printf(" - %3.2lf w) ]",m[1][2] / m[1][1]);
		
		if(m[0][0] != 1) 
			printf(" %c %3.2lf",m[0][0]); */
			
		printf("\n\n\n\t\t\t\t\tX = ( %3.2lf",(m[1][3] / m[1][1]) + m[0][3] );	
		
		if( ( ( m[1][2] / m[1][1] ) - m[0][2] ) < 0)
			printf(" + %3.2lf w)",-1* ( ( m[1][2] / m[1][1] ) + (m[0][2]) ) );
		
		else printf(" - %3.2lf w)",( m[1][2] / m[1][1] ) + (m[0][2]) );
		
		if(m[0][0] != 1)
			printf(" %c %3.2lf",246,m[0][0]);
		
		if(m[1][2]<0)
			printf("\n\n\t\t\t\t\tY = ( %3.2lf + %3.2lf w ) ",m[1][3],-1*m[1][2]);
		
		else printf("\n\n\t\t\t\tY = ( %3.2lf - %3.2lf w ) ",m[1][3],m[1][2]);

		if(m[1][1] != 1)
			printf(" %c %3.2lf",246,m[1][1]);
	
		printf("\n\n\t\t\t\t\tZ = w");	
		
		printf("\n\n\n\t\t\t    Sistema lineal NO homog%cneo (infinitas soluciones).",130);		
		printf("\n\n\t\t\tDonde \"w\" puede ser cualquier valor y siempre ser%c soluci%cn.",160,162);
	}
		
	else 
	{
		z = m[2][3] / m[2][2];
		y = (m[1][3] - ( m[1][2] * z ) ) / m[1][1];
		x =	( (m[0][3] - ( m[0][1] * y ) ) - (m[0][2] * z) ) / m[0][0];
		
		if(z == -0) //Sí lo sé...
			z *= -1;//estas condiciones están medio raras ._.
		
		if(y == -0)//Pero qué le vamos hacer xD
			y *= -1;
		
		if(x == -0)//Cosas de programación xD xD
			x *= -1;
			
		printf("\n\n\n\t\t\t\t\t    X = %4.10lf",x);
		printf("\n\n\t\t\t\t\t    Y = %4.10lf",y);
		printf("\n\n\t\t\t\t\t    Z = %4.10lf",z);	

		printf("\n\n\n\t\t\t\t     Es un sistema lineal no homog%cneo.",130);
	}
}
