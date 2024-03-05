#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <algorithm> 

#include <cassert>
/**
  @brief Stack Class

  Classe templata utilizzata per rappresentare uno stack.
*/

template <typename T> class Stack{
	T* stack; ///< puntatore alla prima cella dell'array.
	int size; ///< numero celle nell'array
	int indice;///<indica in che posizione sarà inserito il prossimo elemento nella lista.parte da 0 .
	public:
	/**
	    @brief costruttore di default
		Il costruttore di default è usato per inizializzare i dati membro per
		rappresentare lo stack vuoto.
	   

	    @post stack = nullptr
	    @post size = 0
		@post indice=0
	*/
	Stack(): stack(nullptr), size(0), indice(0){}
	
	
	
	/**
	    @brief costruttore secondario (size)

	   Il  costruttore secondario è usato per settare lo stack della
	   dimensione che si vuole.

	    @param n indica la dimensione che deve avere lo stack
	    

	    @pre n!=0 

	    @post _matrix != nullptr
	    @post size == z
		@post indice==0
	    

	    @throw std::bad_alloc possibile eccezione di allocazione.
	*/
	
	Stack(int n): stack(nullptr), size(n), indice(0){
		assert(n>0);
		try {
			stack = new T[n];
		}
		catch(...) {
			clear();
			throw;
		}
		
	}
	
	/**
	    @brief Copy Constructor
	    E' usato per creare un oggetto come copia
		di un altro oggetto. I due oggetti devono essere indipendenti.
	    @param Un oggetto di tipo Stack.
	    
	    @post stack != nullptr
	    @post size == other.size
		  @post indice == other.indice
	    @throw std::bad_alloc possibile allocation exception
	*/
	Stack(const Stack &other) : stack(nullptr), size(other.size), indice(0) {
		try {
			stack = new T[size];
			for (unsigned int i = 0; i < size; ++i){
				push(other.stack[i]);
			}
		}
		catch(...) {
			clear();
			throw;
		}
		
	}
	
	
	/**
	    @brief costruttore secondario
	    E' usato per creare un oggetto e riempirlo con un insieme
		di valori ricavati tramite gli iteratori.
	    @param first è un iteratore che punta all'inizio della sequenza di valori con qui inizializzare 
		lo stack
		@param last è un iteratore che punta alla fine della sequenza di valori con qui inizializzare 
		lo stack
		@param n indica la dimensione che deve avere lo stack
	    @post stack != nullptr
	    @post size == n
	    @throw std::bad_alloc possibile allocation exception
	*/
	
	template <typename Iter> Stack(Iter first, Iter last, int n): stack(nullptr), size(n), indice(0){
		try{
			stack = new T[size];
			int i=0;
			while(first!=last && i<size){
			stack[i]=static_cast<T>(*first);
			++first;
			i++;
			indice++;
			}
		}
		catch(...){
			clear();
			throw;
		}

	}	
	
	
	
	/**
	    @brief Operatore di assegnamento
		E' usato per copiare il contenuto di un oggetto 
		dentro un'altro oggetto dello stesso tipo. 
	    I due oggetti devono essere indipendenti.
	    @param un'altro oggetto di tipo Stack.
	    @return viene ritornato un riferimento all'oggetto
		corrente.
	    @post stack != nullptr
	    @post size == other.size
	    
	*/
	Stack &operator=(const Stack &other) {
		if(this != &other) {
		Stack temp(other);
		this->swap(temp);
		}

		return *this;
	}
	

	
	
	
	
	
	/**
	@brief metodo swap
	   funzione utilizzata dall'operatore di assegnamento per assegnare
	   il contenuto di un oggetto ad un'altro.
		
	    @param oggetto Stack
	*/
	void swap(Stack &other) {
        std::swap(this->stack, other.stack);
        std::swap(this->size, other.size);
		  std::swap(this->indice, other.indice);
    }
	
	/**
	    @brief push (elemento)

	   Il metodo push è usato per inserire un elemento in testa allo
	   stack(all'array), quindi vado a inserire l'elemento 
	   nella prima posizione che trovo libera.

	    @param elemento indica l'elemento che voglio aggiungere in
		testa allo stack.
		 @throw genero eccezione quando lo stack è pieno.
	    
	*/
	
	void push(T elemento){
		bool eccezione= true;
		
		try{
			if(this->indice < this->size){
				
				this->stack[this->indice]=elemento;
				this->indice=this->indice + 1;
				eccezione=false;
			}
			
			if(eccezione==true){
				 throw "lo stack e' pieno, quindi non e' possibile fare la push.";
			}
		}
		catch (const char* messaggio) {
		
        std::cerr<<messaggio<< std::endl;
		
			}
		}

		
		/**
	    @brief pop (elemento)

	   Il metodo pop è usato per eliminare l'elemento  in testa allo
	   stack(all'array) e restituirlo.
		 @throw genero eccezione quando lo stack è vuoto. Quindi quando l'indice=0( cioè il prossimo elemento
		 da aggiungere sarà aggiunto in posizione 0, quindi per adesso lo stack è vuoto).
	    
	*/
	
T  pop(){
	T ritorno;
	bool eccezione=true;
	try{
			if(this->indice>=1){
				ritorno= this->stack[indice-1];
				this->indice--;
				eccezione=false;
				
				
		}
		if(eccezione==true){
			 throw "lo stack e' vuoto non ci sono elementi, quindi non e' possibile fare la pop.";
		}
		
	}	
	catch (const char* messaggio) {
		
        std::cerr<<messaggio<<std::endl;
		
    }
		return ritorno;
}

/**
    	@brief metodo clear
		Metodo invocato in caso di eccezione, e dal distruttore.
    	Funzione che svuota l'array Stack, deallocando la memoria allocata sull'heap e portando i dati membro in uno stato coerente.
    	@post stack == nullptr
	    @post size == 0
		@post indice==0
    */

	void clear() {
		delete[] this->stack;
        this->stack = nullptr;
        this->size=0;
		this->indice=0;
    }
	
	/**
	    @brief getSize() serve per ritornare la dimensione dello stack.
    	@return ritorna la grandezza della lista.
	*/
	unsigned int getSize() const{
		return this->size;
	}
	
	/**
	    @brief getPosizioneUltimoElemento serve per ritornare la posizione dell'elemento in testa allo stack.
    	@return ritorna la posizione dell'elemento in testa allo stack.
	*/
	unsigned int getPosizioneUltimoElemento() const{
		return this->indice - 1;
	}
	
	/**
	    @brief getIndice serve per ritornare la posizione del prossimo elemento che sarà aggiunto allo stack.
    	@return ritorna la posizione del prossimo elemento che sarà aggiunto allo stack.
	*/
	unsigned int getIndice() const{
		return this->indice ;
	}
	
	
	/**
	    @brief metodo per svuotare lo stack. 
		Svuoto lo stack logicamente e per farlo setto 
		indice a 0 cosi significa che 0 sarà la prossima 
		posizione dell'elemento che aggiungero all'array
		e che quindi per adesso lo stack è vuoto.
    	@post indice==0 
	*/
	void svuotaStack(){
		this->indice=0;
	}
	
	
	
	/**
	    @brief metodo per riempire lo stack.
		Se vuoto lo riempio utilizzando gli iteratori. Se ha degli elementi lo svuoto e poi lo riempio utilizzando gli iteratori.
		@param first è un iteratore che punta all'inizio della sequenza di valori con qui riempire 
		lo stack
		@param last è un iteratore che punta alla fine della sequenza di valori con qui riempire 
		lo stack
    	
	*/
	
	
	
	template <typename Iter> void fillStack(Iter first, Iter last){
		int i=0;
		T tmp;
		if(this->indice != 0){
			svuotaStack();
		}
		
			while(first!=last && i<this->size){
			
			this->stack[i]=static_cast<T>(*first);
			
			++first;
			i++;
			indice++;
			}
		}
		
		/**
	    @brief metodo per stampare lo stack.
		Ritorna gli elementi dello stack a partire da quello in cima utilizzando iteratore di sola lettura.
	*/
		
	void stampaStack() const{
	int i=0;
	if(this->indice==0){
		std::cout<<"lo stack è vuoto, al momento non ci sono elementi"<<std::endl;
	}
	else{
		const_iterator s((this->end()));
		s--;
		while(s!=this->begin()){
			std::cout<<*s<<std::endl;
			s--;
		}
		if(s== this->begin()){
		std::cout<<*s<<std::endl;
		}
	}	
	}	
		
		
	class const_iterator; // forward declaration
// classe iterator
	class iterator {
		
		private:
		
		T* ptr;
		
	
		friend class Stack;
		explicit iterator(T *dt) : ptr(dt) {}

	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef T*                        pointer;
		typedef T&                        reference;

	
		iterator(): ptr(nullptr) {}
		
		iterator(const iterator &other): ptr(other.ptr) {}

		iterator& operator=(const iterator &other) {
			ptr= other.ptr;
			return *this;
		}

		~iterator() {
			
		}

		
		reference operator*() const {
			return *ptr;
		}

		
		pointer operator->() const {
			return ptr;
		}

		
		iterator operator++(int) {
			return iterator(ptr++);
		}

		
		iterator& operator++() {
			++ptr;
			return *this;
		}
	iterator operator--(int) {
			return iterator(ptr--);
		}

		
		iterator& operator--() {
			--ptr;
			return *this;
		}
		
		bool operator==(const iterator &other) const {
			return (ptr==other.ptr);
		}

		
		bool operator!=(const iterator &other) const {
			return (ptr!= other.ptr);
		}
		
		
		friend class const_iterator;

		
		bool operator==(const const_iterator &other) const {
			return ptr== other.ptr;
		}

		
		bool operator!=(const const_iterator &other) const {
			return ptr!= other.ptr;
		}

		

	
		
	}; 
	
	
	iterator begin() {
		return iterator(stack);
	}
	
	
	iterator end() {
		return iterator(stack+ indice);
	}
	
	
	//classe const iterator
	class const_iterator {
		private:
			T* ptr;
		
		friend class Stack; 
		explicit const_iterator(T *dt): ptr(dt) {}

	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

	
		const_iterator(): ptr(nullptr) {}
		
		const_iterator(const const_iterator &other): ptr(other.ptr) {}

		const_iterator& operator=(const const_iterator &other) {
			ptr=other.ptr;
			return *this;
		}

		~const_iterator() {
		
		}

		
		reference operator*() const {
			return *ptr;
		}

	
		pointer operator->() const {
			return ptr;
		}
		
	
		const_iterator operator++(int) {
			return const_iterator(ptr++);
		}

		
		const_iterator& operator++() {
			++ptr;
			return *this;
		}
		const_iterator operator--(int) {
			return const_iterator(ptr--);
		}

		
		const_iterator& operator--() {
			--ptr;
			return *this;
		}
		
		bool operator==(const const_iterator &other) const {
			return (ptr== other.ptr);
		}
		
		
		bool operator!=(const const_iterator &other) const {
			return (ptr!= other.ptr);
		}

		friend class iterator;

		
		bool operator==(const iterator &other) const {
			return (ptr== other.ptr);
		}

		
		bool operator!=(const iterator &other) const {
				return (ptr!= other.ptr);
		}

		// Costruttore di conversione iterator -> const_iterator
		const_iterator(const iterator &other): ptr(other.ptr) {
		}

		

	
		
	}; // classe const_iterator
	
	
	const_iterator begin() const {
		return const_iterator(stack);
	}
	
	
	const_iterator end() const {
		return const_iterator(stack + indice);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

/**
	    @brief Distruttore
	    Il distruttore deve rimuovere tutte le risorse utilizzate dalla classe.
		In questo caso l'array allocato nell'heap deve essere deallocato e gli
		altri dati membro devono essere riportati a uno stato coerente.
	    @post stack == nullptr
	    @post size == 0
		@post indice== 0
	  
	*/
    ~Stack() {
        clear();
    }
	
	
	

	/**
    @brief funzione  checkif
    funzione generica che dato in input un dato dello stesso tipo di stack
	mi restituisce se il dato rispetta il predicato o no.
	
    @param elemento indica il dato dello stesso tipo di stack, di cui bisogna verificare se rispetta il predicato.
    @param pred è il predicato che deve soddisfare il parametro elemento. 
    @return true/false
*/

template <typename F> bool checkif(const T elemento, F pred) const{
return pred(elemento);	

}
	
	
	
	


	
};







#endif