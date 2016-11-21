//---------------------------------------------------------------------------

#ifndef Juego_H
#define Juego_H

	class Juego {
		private:
			int nivel ;


		public:
			Juego () ;
			int getNivel ( ) ;
			void setNivel ( int Nivel )  ;

	};

	int Juego::getNivel ( ) {
		return nivel;
	}

	void Juego::setNivel ( int Nivel ) {
		nivel = Nivel ;
    }

//---------------------------------------------------------------------------
#endif
