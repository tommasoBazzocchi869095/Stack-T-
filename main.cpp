#include <iostream>
#include <algorithm>

#include "stack.h"
using namespace std;
struct customType {

    int a;
    double b;
    char c;

    customType() : a(0), b(0), c('a') {}

    customType(int a, double b, char c) : a(a), b(b), c(c) {}

    customType(const customType &other) {
        a = other.a;
        b = other.b;
        c = other.c;
    }

    customType(char c) : a(0), b(0), c(c) {}

    customType &operator=(const customType &other) {
        if(this!=&other) {
            customType tmp(other);
            swap(a, tmp.a);
            swap(b, tmp.b);
            swap(c, tmp.c);
        }

        return *this;
    }

    ~customType() {};

    bool operator==(const customType &other) const {
        return a == other.a && b == other.b && c == other.c;
    }

    bool operator!=(const customType &other) const {
        return !(*this == other);
    }

    friend ostream &operator<<(std::ostream &os, const customType &custom) {
        
        os << "(" << custom.a << "," << custom.b << "," << custom.c << ")";

        return os;
    }

    void increase(int a, double b, int c) {
        a += a;
        b += b;
        c += c;

    }

    void init(int a, double b, char c) {
        a = a;
        b = b;
        c = c;
    }

};


//test costruttore di default
void test_defaultconstructor(){
	std::cout << "Costruttore di default" << std::endl;
	Stack<int> stack;
	Stack<char> stack2;
	Stack<customType> stack3;
	assert(stack.getSize()==0 && stack.getIndice()==0);
	assert(stack2.getSize()==0 && stack2.getIndice()==0);
	assert(stack3.getSize()==0 && stack3.getIndice()==0);
	std::cout<<std::endl;
}

//test costruttore secondario
void test_secondaryconstructor() {
	std::cout << "Costruttore secondario" <<std::endl;
	Stack<int> stack2(10);
	Stack<char> stack3(5);
	Stack<customType> stack4(8);
	assert(stack2.getSize()==10 && stack2.getIndice()==0);
	assert(stack3.getSize()==5 && stack3.getIndice()==0);
	assert(stack4.getSize()==8 && stack4.getIndice()==0);
	
	std::cout<<std::endl;
}

//test copy constructor
void testcopyconstructor() {
	std::cout<<"copy constructor"<<std::endl;
	Stack<int> stack(5);
	Stack<char> stack2(5);
	Stack<customType> stack3(5);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	std::cout<<"stampa Stack<int> stack: "<<std::endl;
	stack.stampaStack();
	Stack<int> stack1(stack);
	std::cout<<"stampiamo Stack<int> stack1 creata come copia di Stack<int> stack"<<std::endl;
	stack1.stampaStack();
	assert(stack.getSize()==stack1.getSize() && stack.getIndice()==stack1.getIndice());
	stack2.push('a');
	stack2.push('b');
	stack2.push('c');
	stack2.push('d');
	stack2.push('e');
	
	std::cout<<"stampa Stack<char> stack2(5): "<<std::endl;
	stack2.stampaStack();
	Stack<char> stack4(stack2);
	std::cout<<"stampa Stack<char> stack4 creata come copia di Stack<char> stack2: "<<std::endl;
	stack4.stampaStack();
	assert(stack2.getSize()==stack4.getSize() && stack2.getIndice()==stack4.getIndice());
	customType custom(4, 78, 's');
	customType custom1(5, 3, 'a');
	customType custom2(7, 2, 'b');
	customType custom3(8, 2, 'c');
	customType custom4(9, 2, 'd');
	stack3.push(custom);
	stack3.push(custom1);
	stack3.push(custom2);
	stack3.push(custom3);
	stack3.push(custom4);
	std::cout<<"stampa Stack<customType> stack3(5): "<<std::endl;
	stack3.stampaStack();
	Stack<customType> stack5(stack3);
	std::cout<<"stampa Stack<customType> stack5 creata come copia di Stack<customType> stack3: "<<std::endl;
	stack5.stampaStack();
	assert(stack3.getSize()==stack5.getSize() && stack3.getIndice()==stack5.getIndice());
	
	}








// test del costruttore secondario con parametro
// una coppia di iteratori che punta uno all'inizio di una 
//sequenza e uno alla fine.
void testCostruttoreIteratore(){
	std::cout<<"test per testare il costruttore con input degli iteratori che puntano a una sequenza, e che riempie lo stack con questa sequenza"<<std:: endl;
	Stack<int> A(5);
	Stack<char> C(5);
	A.push(6);
	A.push(7);
	A.push(8);
	A.push(9);
	A.push(10);
	std::cout<<" stampa Stack<int> A(5): "<<std::endl;
	A.stampaStack();
	Stack<int> B(A.begin(),A.end(), 5);
	std::cout<<"stampa Stack<int> B(A.begin(),A.end(), 5): "<<std::endl;
	B.stampaStack();
	C.push('a');
	C.push('b');
	C.push('c');
	C.push('d');
	C.push('e');
	std::cout<<"stampa Stack<char> C(5):"<<std::endl;
	C.stampaStack();
	Stack<char> D(C.begin(), C.end(), 5);
	std::cout<<"stampa Stack<char> D(C.begin(), C.end(), 5): "<<std::endl;
	D.stampaStack();
	
	Stack<customType> stack6(10);
	
	customType custom(8, 42, 'x');
	customType custom1(56, 32, 'k');
	customType custom2(41, 89, 'l');
	customType custom3(3, 7, 'g');
	customType custom4(56, 98, 'd');
	customType custom5(7, 8, 'a');
	customType custom6(5, 8, 'f');
	customType custom7(6, 9, 'c');
	customType custom8(4, 6, 'r');
	customType custom9(5, 5, 's');
	stack6.push(custom);
	stack6.push(custom1);
	stack6.push(custom2);
	stack6.push(custom3);
	stack6.push(custom4);
	stack6.push(custom5);
	stack6.push(custom6);
	stack6.push(custom7);
	stack6.push(custom8);
	stack6.push(custom9);
	std::cout<<"stampa Stack<customType> stack6(10):"<<std::endl;
	stack6.stampaStack();
	Stack<customType> stack7(stack6.begin(), stack6.end(), 10);
	std::cout<<"stampa Stack<customType> stack7(stack6.begin(), stack6.end(), 10):"<<std::endl;
	stack7.stampaStack();
}
//test operatore di assegnamento.
void testOperatoreAssegnamento(){
	std::cout<<"test operatore di assegnamento: "<<std::endl;
	Stack<int> stack1(5);
	Stack<char> stack3(5);
	Stack<customType> stack5(5);
	stack1.push(67);
	stack1.push(68);
	stack1.push(69);
	stack1.push(70);
	stack1.push(71);
	std::cout<<"stampa Stack<int> stack1(5):"<<std::endl;
	stack1.stampaStack();
	Stack<int> stack2;
	stack2=stack1;
	std::cout<<"stampa Stack<int> stack2 ottenuto dall'assegnamento stack2=stack1:"<<std::endl;
	stack2.stampaStack();
	assert(stack1.getSize()==stack2.getSize() && stack1.getIndice()==stack2.getIndice());
	stack3.push('f');
	stack3.push('g');
	stack3.push('a');
	stack3.push('l');
	stack3.push('m');
	std::cout<<"stampa Stack<char> stack3(5):"<<std::endl;
	stack3.stampaStack();
	Stack<char> stack4;
	stack4=stack3;
	std::cout<<"stampa Stack<char> stack4 ottenuto dall'assegnamento stack4=stack3:"<<std::endl;
	stack4.stampaStack();
	assert(stack3.getSize()==stack4.getSize() && stack3.getIndice()==stack4.getIndice());
	customType custom(5, 42, 'x');
	customType custom1(6, 32, 'k');
	customType custom2(7, 89, 'l');
	customType custom3(8, 7, 'g');
	customType custom4(9, 98, 'd');
	stack5.push(custom);
	stack5.push(custom1);
	stack5.push(custom2);
	stack5.push(custom3);
	stack5.push(custom4);
	std::cout<<"stampa 	Stack<customType> stack5(5):"<<std::endl;
	stack5.stampaStack();
	Stack<customType> stack6;
	stack6=stack5;
	std::cout<<"stampa Stack<customType> stack6 ottenuto dall'assegnamento stack6=stack5: "<<std::endl;
	stack6.stampaStack();
	assert(stack5.getSize()==stack6.getSize() && stack5.getIndice()==stack6.getIndice());
}



//test metodo push
void testPush(){
	std::cout<<"test push: "<<std::endl;
	Stack<int> stack(10);
	Stack<char> stack1(5);
	Stack<customType> stack2(2);
	stack.push(2);
	stack.push(5);
	stack.push(4);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	stack.push(9);
	stack.push(10);
	stack.push(11);
	stack.push(12);
	std::cout<<"stampa Stack<int> stack(10): "<<std::endl;
	stack.stampaStack();
	assert(stack.getIndice()==10 && stack.getPosizioneUltimoElemento()==9);
	stack1.push('a');
	stack1.push('b');
	stack1.push('e');
	stack1.push('f');
	stack1.push('s');
	std::cout<<"stampa Stack<char> stack1(5): "<<std::endl;
	stack1.stampaStack();
	assert(stack1.getIndice()==5 && stack1.getPosizioneUltimoElemento()==4);
	customType custom(5, 42, 'x');
	customType custom1(6, 32, 'k');
	stack2.push(custom);
	stack2.push(custom1);
	std::cout<<"stampa Stack<customType> stack2(2): "<<std::endl;
	stack2.stampaStack();
	assert(stack2.getIndice()==2 && stack2.getPosizioneUltimoElemento()==1);	
}

//test metodo pop
void testPop(){
	std::cout<<"test metodo pop: "<<std::endl;
	Stack<int> stack(10);
	Stack<char> stack1(5);
	Stack<customType> stack2(2);
	stack.push(2);
	stack.push(5);
	stack.push(4);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	stack.push(9);
	stack.push(10);
	stack.push(11);
	stack.push(12);
	std::cout<<"stampa Stack<int> stack(10): "<<std::endl;
	stack.stampaStack();
	std::cout<<"ora facciamo due pop e vediamo cosa ritorna: "<<std::endl;
	std::cout<<stack.pop()<<std::endl;
	std::cout<<stack.pop()<<std::endl;
	assert(stack.getIndice()==8);
	stack1.push('a');
	stack1.push('b');
	stack1.push('e');
	stack1.push('f');
	stack1.push('s');
	std::cout<<"stampa Stack<char> stack1(5): "<<std::endl;
	stack1.stampaStack();
	std::cout<<"ora facciamo due pop e vediamo cosa ritorna: "<<std::endl;
	std::cout<<stack1.pop()<<std::endl;
	std::cout<<stack1.pop()<<std::endl;
	assert(stack1.getIndice()==3);
	customType custom(5, 42, 'x');
	customType custom1(6, 32, 'k');
	stack2.push(custom);
	stack2.push(custom1);
	std::cout<<"stampa Stack<customType> stack2(2): "<<std::endl;
	stack2.stampaStack();
	std::cout<<"ora facciamo due pop e vediamo cosa ritorna: "<<std::endl;
	std::cout<<stack2.pop()<<std::endl;
	std::cout<<stack2.pop()<<std::endl;
	assert(stack2.getIndice()==0);
}

// test metodo per ottenere size
void testGetSize(){
	std::cout<<"test metodo getSize(): "<<std::endl;
	Stack<int> stack(10);
	Stack<char> stack1(5);
	Stack<customType> stack2(2);
	std::cout<<" la size di Stack<int> stack(10) e': "<< stack.getSize()<<std::endl;
	std::cout<<" la size di Stack<char> stack1(5) e': "<< stack1.getSize()<<std::endl;
	std::cout<<" la size di Stack<customType> stack2(2) e': "<< stack2.getSize()<<std::endl;
	assert(stack.getSize()==10 && stack.getIndice()==0 && stack1.getSize()==5 && stack1.getIndice()==0 && stack2.getSize()==2 && stack2.getIndice()==0);
	}

//test metodo per ottenere posizione ultimo elemento(quello in testa)

void testGetPosizioneUltimoElemento(){
std::cout<<"test getPosizioneUltimoElemento(testa): "<<std::endl;
	Stack<int> stack(10);
	Stack<char> stack1(5);
	Stack<customType> stack2(2);
	stack.push(2);
	stack.push(5);
	stack.push(4);
	std::cout<<"stampiamo Stack<int> stack(10): "<<std::endl;
	stack.stampaStack();
	std::cout<<"la posizione dell'elemento in testa a Stack<int> stack(10) è: "<<stack.getPosizioneUltimoElemento()<<std::endl;
	
	stack1.push('a');
	stack1.push('b');
	std::cout<<"stampiamo Stack<char> stack1(5): "<<std::endl;
	stack1.stampaStack();
	std::cout<<"la posizione dell'elemento in testa a Stack<char> stack1(5) è: "<<stack1.getPosizioneUltimoElemento()<<std::endl;
	
	customType custom(5, 42, 'x');
	customType custom1(6, 32, 'k');
	stack2.push(custom);
	stack2.push(custom1);
	std::cout<<"stampiamo Stack<customType> stack2(2): "<<std::endl;
	stack2.stampaStack();
	std::cout<<"la posizione dell'elemento in testa a Stack<customType> stack2(2) è: "<<stack2.getPosizioneUltimoElemento()<<std::endl;

	assert(stack.getPosizioneUltimoElemento()==2 && stack1.getPosizioneUltimoElemento()==1 && stack2.getPosizioneUltimoElemento()==1);
	


}
	
	//test metodo per ottenere l'indice
	void testGetIndice(){
		std::cout<<"test metodo getIndice(): "<<std::endl;
	Stack<int> stack(10);
	Stack<char> stack1(5);
	Stack<customType> stack2(2);
	stack.push(2);
	stack.push(5);
	stack.push(4);
	stack.push(6);
	stack.push(7);
	std::cout<<"stampa Stack<int> stack(10): "<<std::endl;
	stack.stampaStack();
	std::cout<<"l'indice di Stack<int> stack(10) e': "<<stack.getIndice()<<std::endl;
	assert(stack.getIndice()==5);
	stack1.push('a');
	stack1.push('b');
	stack1.push('e');
	std::cout<<"stampa Stack<char> stack1(5): "<<std::endl;
	stack1.stampaStack();
	std::cout<<"l'indice di Stack<char> stack1(5) e': "<<stack1.getIndice()<<std::endl;
	assert(stack1.getIndice()==3);
	customType custom(5, 42, 'x');
	customType custom1(6, 32, 'k');
	stack2.push(custom);
	stack2.push(custom1);
	std::cout<<"stampa Stack<customType> stack2(2): "<<std::endl;
	stack2.stampaStack();
	std::cout<<"l'indice di Stack<char> stack2(5) e': "<<stack2.getIndice()<<std::endl;
	assert(stack2.getIndice()==2);
}
	


//test metodo svuotaStack
void testSvuotaStack(){
	std::cout<<"test metodo che svuota lo stack "<<std::endl;
	Stack<int> stack1(10);
	Stack<char> stack2(3);
	Stack<customType> stack3(3);
	stack1.push(2);
	stack1.push(5);
	stack1.push(4);
	stack1.push(3);
	stack1.push(3);
	stack1.push(3);
	stack1.push(3);
	stack1.push(3);
	stack1.push(3);
	stack1.push(3);
	stack2.push('a');
	stack2.push('b');
	stack2.push('c');
	stack1.svuotaStack();
	stack2.svuotaStack();
	customType custom(5, 35, 'x');
	customType custom1(6, 44, 'k');
	customType custom2(7, 56, 'k');
	stack3.push(custom);
	stack3.push(custom1);
	stack3.push(custom2);
	stack3.svuotaStack();
	assert(stack1.getIndice()==0 && stack2.getIndice()==0 && stack3.getIndice()==0);
	
}
	//test del metodo che riempie lo stack con gli elementi di un altro stack attraverso una coppia di iteratori.
void testfillStack(){
	std::cout<<"test del metodo fillStack:"<<std::endl;
	Stack<customType> stack6(10);
	
	customType custom(8, 42, 'x');
	stack6.push(custom);
	stack6.push(custom);
	stack6.push(custom);
	stack6.push(custom);
	stack6.push(custom);
	stack6.push(custom);
	stack6.push(custom);
	stack6.push(custom);
	stack6.push(custom);
	stack6.push(custom);
	std::cout<<"stampo Stack<customType> stack6(10): "<<std::endl;
	stack6.stampaStack();
	
	Stack<customType> stack7(10);
	customType custom1(6, 53, 'd');
	stack7.push(custom1);
	stack7.push(custom1);
	std::cout<<"stampo  Stack<customType> stack7(10): "<<std::endl;
	stack7.stampaStack();
	
	stack7.fillStack(stack6.begin(), stack6.end());
	std::cout<<"ora stampo Stack<customType> stack7(10) dopo aver invocato stack7.fillStack(stack6.begin(), stack6.end()): "<<std::endl;
	stack7.stampaStack();

	
	Stack<int> C(5);
	C.push(1);
	C.push(2);
	C.push(3);
	C.push(4);
	C.push(5);
	std::cout<<"stampo Stack<int> C(5): "<<std::endl;
	C.stampaStack();
	Stack<int> D(5);
	D.push(67);
	D.push(80);
	std::cout<<"stampo Stack<int> D(5): "<<std::endl;
	D.stampaStack();
	
	D.fillStack(C.begin(),C.end());
	std::cout<<"ora stampo Stack<int> D(5) dopo aver invocato D.fillStack(C.begin(),C.end()): "<<std::endl;
	D.stampaStack();
	
	Stack<char> E(5);
	E.push('a');
	E.push('a');
	E.push('a');
	std::cout<<"stampo Stack<char> E(5): "<<std::endl;
	E.stampaStack();
	Stack<char> F(5);
	F.push('a');
	F.push('b');
	F.push('c');
	std::cout<<"stampo Stack<char> F(5): "<<std::endl;
	F.stampaStack();
	F.fillStack(E.begin(),E.end());
	std::cout<<"ora stampo Stack<char> F(5) dopo aver invocato F.fillStack(E.begin(),E.end()): "<<std::endl;
	F.stampaStack();
	
}

void testStampaStack(){
	std::cout<<"test metodo stampaStack: "<<std::endl;
	Stack<int> stack1(5);
	Stack<char> stack2(4);
	Stack<customType> stack3(4);
	stack1.push(6);
	stack1.push(7);
	stack1.push(8);
	stack1.push(9);
	std::cout<<"stampa Stack<int> stack1(5): "<<std::endl;
	stack1.stampaStack();
	stack2.push('a');
	stack2.push('b');
	stack2.push('c');
	stack2.push('d');
	std::cout<<"stampa Stack<char> stack2(4): "<<std::endl;
	stack2.stampaStack();
	customType custom(5, 35, 'x');
	customType custom1(6, 44, 'k');
	customType custom2(7, 56, 'k');
	stack3.push(custom);
	stack3.push(custom1);
	stack3.push(custom2);
	std::cout<<"stampa Stack<customType> stack3(4): "<<std::endl;
	stack3.stampaStack();
	
}


struct my_functor_test{
	bool operator()(int a) const{return a>0;}
	
};
struct my_functor_test1{
	bool operator()(char a) const{return a=='a';}
	
};
struct my_functor_test3{
	bool operator()(customType a) const{return ( a.a %2 ==0 && (int(a.b) % 2==0) && a.c =='x');}
	
};
 
void testCheckif(){
	Stack<int> test1(5);
	int a=8;
	char b='a';
	Stack<char> test2(5);
	Stack<customType> test3(5);
	customType custom(5, 35, 'x');
	std::cout<<"test checkif  chiamato sull'oggetto Stack<customType> test3(5) con parametri la variabile custom e il funtore my_functor_test3: "<< (test3.checkif(custom, my_functor_test3())? "true" : "false")<<std::endl;
	std::cout<<"test checkif chiamato sull'oggetto Stack<int> test1(5) con parametri la variabile a e il funtore my_functor_test: "<<(test1.checkif(a, my_functor_test())? "true" : "false") <<std::endl;
	std::cout<<"test checkif chiamato sull'oggetto Stack<char> test2(5) con parametri la variabile b e il funtore my_functor_test1: " <<(test2.checkif(b, my_functor_test1())? "true" : "false") <<std::endl; 	
	assert(test3.checkif(custom, my_functor_test3())==false && test1.checkif(a, my_functor_test())==true && test2.checkif(b, my_functor_test1())==true);
	
	}

int main(){
	std::cout<<" INIZIO TEST"<<std::endl;
	std::cout<<"ATTENZIONE: i vari metodi implementati nel file stack.h hanno tutti un metodo test apposito dove vengono testati,"<<std::endl;
	std::cout<<" quindi i nomi delle variabili utilizzate per il test di un metodo possono coincidere con i nomi di variabili utilizzate per il test di un altro metoto."<<std::endl;
	std::cout<<" ma sono variabili diverse non hanno niente in comune hanno semplicemente lo stesso nome."<<std::endl;
	std::cout<<"tutte le stampe che vengono fatte all'interno dei test sono fatte utilizzando il metodo stampaStack che stampa a partire dalla testa e quindi dall'ultimo elemento inserito"<<std::endl;
	std::cout<<std::endl;
	test_defaultconstructor();
	std::cout<<std::endl;
	test_secondaryconstructor();
	std::cout<<std::endl;
	testcopyconstructor();
	std::cout<<std::endl;
	testOperatoreAssegnamento();
	std::cout<<std::endl;
	testPush();
	std::cout<<std::endl;
	testPop();
	std::cout<<std::endl;
	testSvuotaStack();
	std::cout<<std::endl;
	testGetSize();
	std::cout<<std::endl;
	testGetIndice();
	std::cout<<std::endl;
	testGetPosizioneUltimoElemento();
	std::cout<<std::endl;
	testfillStack();
	std::cout<<std::endl;
	testCheckif();
	std::cout<<std::endl;
	testCostruttoreIteratore();
	std::cout<<std::endl;
	testStampaStack();
	std::cout<<std::endl;
	std::cout<<"fine test"<<std::endl;
	return 0;
}
	
	
