#include "Theme.h"

Theme::Theme()
{
}

Theme::~Theme()
{
}

void Theme::setArtQuestions()
{
	if (questions.size() == 0) {
		//Arte // 0 - 4
		questions.push_back("1) Uno de los siguientes personajes fue el\nencargado de pintar la capilla Sixtina: ");
		questions.push_back("2) Genio del renacimiento que esculpió el Moisés,\nel David y la Pietá: ");
		questions.push_back("3) Durante el renacimiento el estilo artístico que\nimpregnó el arte, la filosofía, la pintura\nescritura fue el: ");
		questions.push_back("4) Durante el renacimiento surge una nueva visión\ndel hombre, que se vio reflejada en el arte, en\nla y en las ciencias sociales y humanas, a lo que\nse denomina : ");
		questions.push_back("5) Cuatro genios del renacimiento\n(Leonardo, Donatello, Rafael y Michelangelo)\nhan sido llevados a la pantalla en los comics de: ");
	}
}

void Theme::setArtAnswers()
{
	if (answers.size() == 0) {
		//Arte // 0 - 19
		// 1st
		answers.push_back("A) Miguel Ángel"); // correcta
		answers.push_back("B) Donatello");
		answers.push_back("C) Leonardo da Vinci");
		answers.push_back("D) Francis Bacon");
		// 2nd 
		answers.push_back("A) Miguel Ángel\n   Buonarroti"); // correcta
		answers.push_back("B) Leonardo Da Vinci");
		answers.push_back("C) Rafael Sanzio");
		answers.push_back("D) Galileo Galilei");
		// 3rd
		answers.push_back("A) El Gótico");
		answers.push_back("B) El barroco"); // correcta
		answers.push_back("C) el clasicismo");
		answers.push_back("D) Romanticismo");
		// 4th
		answers.push_back("A) Antropocentrismo");
		answers.push_back("B) Humanismo"); // correcta
		answers.push_back("C) Paradigma\n    antropológico");
		answers.push_back("D) Teocentrismo");
		// 5th
		answers.push_back("A) Las tortugas\n   ninjas"); // correcta
		answers.push_back("B) Los caballeros\n  del Zodiaco");
		answers.push_back("C) Los cuatro\n   fantásticos");
		answers.push_back("D) Los antagonistas\n   de Attack Titan");
	}
}

void Theme::setPoliticsQuestions()
{
	if (questions.size() == 0) {
		//Politica // 0 - 4
		questions.push_back("1) Durante el renacimiento, el modelo de gobierno\nes uno de los siguientes: ");
		questions.push_back("2) De los siguientes acontecimientos, seleccione\nel que inicia el período moderno: ");
		questions.push_back("3) Durante el siglo XV, la sociedad se estratifica\nen tres estamentos definidos: ");
		questions.push_back("4) Aparece el realismo político, que se basaba en\nun orden establecido, explicación de un sistema y\nrecomendaciones de como gobernar : ");
		questions.push_back("5) Terminada la edad media, en el contexto de la\npolítica resulta que: ");
	}
}

void Theme::setPoliticsAnswers()
{
	if (answers.size() == 0) {
		//Politica // 0 - 19
		// 1st
		answers.push_back("A) Monarquía absoluta"); // correcta
		answers.push_back("B) Tiranía republicana");
		answers.push_back("C) Democracia participativa");
		answers.push_back("D) Liberalismo político");
		// 2nd
		answers.push_back("A) Toma de Constantinopla");
		answers.push_back("B) Tratado de paz de westfalia"); // correcta
		answers.push_back("C) Toma de la Bastilla");
		answers.push_back("D) La ruta de la seda");
		// 3rd
		answers.push_back("A) Clase media, baja y alta");
		answers.push_back("B) Nobleza, clero y estado llano"); // correcta
		answers.push_back("C) Artesanos, guardianes y gobernantes");
		answers.push_back("D) Publico, protegido y privado");
		// 4th
		answers.push_back("A) Tomás Moro");
		answers.push_back("B) Jean Bodín");
		answers.push_back("C) Nicolas Maquiavelo"); // correcta
		answers.push_back("D) Erasmo de Rotterdam.");
		// 5th
		answers.push_back("A) La Iglesia resalta su poder");
		answers.push_back("B) La Iglesia pierde el papel rector en la política"); // correcta
		answers.push_back("C) La Iglesia evangélica se posiciona en la política");
		answers.push_back("D) La política desaparece");
	}
}

void Theme::setScienceQuestions()
{
	if (questions.size() == 0) {
		//Ciencia // 0 -4
		questions.push_back("1) Entre los siguientes renacentistas seleccione,\nuno de los precursoresfilósofo-científico del\nheliocentrismo (teoría que afirma que el sol\nes el centro del universo): ");
		questions.push_back("2) El método científico se introduce por el interés\nde tres filósofos. Entre los siguientes uno de\nlos mencionados no es precursor del métodol\ncientífico: ");
		questions.push_back("3) Es uno de los precursores del pensamiento\nModerno: ");
		questions.push_back("4) De los siguientes filósofos niega el\ngeocentrismo (teoría que afirma que el centro de\nnuestro sistema solar es la tierra): ");
		questions.push_back("5) Uno de los inventos que suscitó un conocimiento\nilimitado, fue el de Gutenberg: ");
	}
}

void Theme::setScienceAnswers()
{
	if (answers.size() == 0) {
		//Ciencia // 0 - 19
		// 1st
		answers.push_back("A) Tomas Moro");
		answers.push_back("B) Galileo"); // correcta
		answers.push_back("C) Platón");
		answers.push_back("D) Arquimedes");
		// 2nd
		answers.push_back("A) Francis Bacon");
		answers.push_back("B) Galileo Galilei");
		answers.push_back(" C)Nicolas Maquiavelo"); // correcta
		answers.push_back("D) René Descartes");
		// 3rd
		answers.push_back("A) Isaac Newton");
		answers.push_back("B) René Descartes"); // correcta
		answers.push_back("C) Erasmo de Roterdam");
		answers.push_back("D) Francis Bacon");
		// 4th
		answers.push_back("A) Aristóteles");
		answers.push_back("B) Nicolás Copérnico"); // correcta
		answers.push_back("C) Tomás de Aquino");
		answers.push_back("D) Isaac Newton");
		// 5th
		answers.push_back("A) El astrolabio");
		answers.push_back("B) La imprenta"); // correcta
		answers.push_back("C) La Nao y la Carabela");
		answers.push_back("D) El Telescopio");
	}
}

void Theme::setHistoryQuestions()
{
	if (questions.size() == 0) {
		//Historia // 0 - 4
		questions.push_back("1) Después del feudalismo medieval acudimos al\nsurgimiento de una nueva clase social conocida\ncomo la: ");
		questions.push_back("2) El renacimiento supone una época de absolutismo\ny nacionalismos, como el nacimiento de fuertes\nmonarquías europeas centralizadas como: ");
		questions.push_back("3) Antes de la consolidación del estado moderno,\nItalia estuvo divida en pequeñas ciudades-estado\nnormalmente enfrentadas entre si, como es el caso \nde: ");
		questions.push_back("4) La toma de Constantinopla supone un bloqueo\ncomercial entre Europa y Asia (la ruta de la seda)\ny ocurrió en lo que hoy es actualmente: ");
		questions.push_back("5) Resurge el interés por Grecia y Roma, junto al\ndeclive del sistema feudal, el crecimiento del\ncomercio e innovaciones entre las que mencionamos: ");
	}
}

void Theme::setHistoryAnswers()
{
	if (answers.size() == 0) {
		//Historia // 0 - 19
		// 1st
		answers.push_back("A) La monarquía");
		answers.push_back("B) El mercantilismo");
		answers.push_back("C) La burguesía"); // correcta
		answers.push_back("D) El proletariado");
		// 2nd
		answers.push_back("A) Grecia");
		answers.push_back("B) Inglaterra"); // correcta
		answers.push_back("C) Yugoslavia");
		answers.push_back("D) Egipto");
		// 3rd
		answers.push_back("A) Florencia-Napoli"); // correcta
		answers.push_back("B) Ámsterdam-Cracovia");
		answers.push_back("C) Reims-Colonia");
		answers.push_back("D) Milán-Lourdes");
		// 4th
		answers.push_back("A) Eslovaquia");
		answers.push_back("B) Estambul en Turquía"); // correcta
		answers.push_back("C) Mesopotamia");
		answers.push_back("D) Jerusalén");
		// 5th
		answers.push_back("A) La imprenta y la brújula"); // correcta
		answers.push_back("B) La rueda y la escritura");
		answers.push_back("C) Las máquinas de vapor y la producción en masa");
		answers.push_back("D) La pólvora y La rueda");
	}
}

void Theme::setBackground(sf::Texture& texture, sf::IntRect rect)
{
	background.setTexture(texture);
	background.setTextureRect(rect);
}

void Theme::drawAt(sf::RenderTarget& target)
{
	target.draw(background);
}

vector<string> Theme::getQuestions()
{
	return questions;
}

vector<string> Theme::getAnswers()
{
	return answers;
}

void Theme::setQuestions()
{
	//Arte // 0 - 4
	/* 0 */ questions.push_back("Uno de los siguientes personajes fue el encargado de pintar la capilla Sixtina: ");
	/* 1 */ questions.push_back("Genio del renacimiento que esculpió el Moisés, el David y la Pietá: ");
	/* 2 */ questions.push_back("Durante el renacimiento el estilo artístico que impregnó el arte, la filosofía, la pintura escritura fue el: ");
	/* 3 */ questions.push_back("Durante el renacimiento surge una nueva visión del hombre,\n que se vio reflejada en el arte, en la y\n en las ciencias sociales y humanas, a lo que se denomina : ");
	/* 4 */ questions.push_back("Cuatro genios del renacimiento (Leonardo, Donatello, Rafael y Michelangelo) han sido llevados a la pantalla en los comics de :");

	//Politica // 5 - 9
	/* 5 */ questions.push_back("Durante el renacimiento, el modelo de gobierno es uno de los siguientes: ");
	/* 6 */ questions.push_back("De los siguientes acontecimientos, selecciones el que inicia el período moderno: ");
	/* 7 */ questions.push_back("Durante el siglo XV, la sociedad se estratifica en tres estamentos definidos: ");
	/* 8 */ questions.push_back("Aparece el realismo político, que se basaba en un orden establecido, explicación de un sistema y recomendaciones de como gobernar : ");
	/* 9 */ questions.push_back("Terminada la edad media, en el contexto de la política resulta que: ");

	//Ciencia // 10 - 14
	/* 10 */ questions.push_back("Entre los siguientes renacentistas seleccione, uno de los precursoresfilósofo-científico del heliocentrismo (teoría que afirma que el sol es el centro del universo) : ");
	/* 11 */ questions.push_back("El método científico se introduce por el interés de tres filósofos. Entre los siguientes uno de los mencionados no es precursor del método científico : ");
	/* 12 */ questions.push_back("Es uno de los precursores del pensamiento Moderno: ");
	/* 13 */ questions.push_back("De los siguientes filósofos niega el geocentrismo (teoría que afirma que el centro de nuestro sistema solar es la tierra) : ");
	/* 14 */ questions.push_back("Uno de los inventos que suscitó un conocimiento ilimitado, fue el de Gutenberg: ");

	//Historia // 15 - 19
	/* 15 */ questions.push_back("Después del feudalismo medieval acudimos al surgimiento de una nueva clase social conocida como la: ");
	/* 16 */ questions.push_back("El renacimiento supone una época de absolutismo y nacionalismos, como el nacimiento de fuertes monarquías europeas centralizadas como : ");
	/* 17 */ questions.push_back("Antes de la consolidación del estado moderno, Italia estuvo divida en pequeñas ciudades-estado normalmente enfrentadas entre si, como es el caso de : ");
	/* 18 */ questions.push_back("La toma de Constantinopla supone un bloqueo comercial entre Europa y Asia (la ruta de la seda) y ocurrió en lo que hoy es actualmente : ");
	/* 19 */ questions.push_back("Resurge el interés por Grecia y Roma, junto al declive del sistema feudal, el crecimiento del comercio e innovaciones entre las que mencionamos : ");
}

void Theme::setAnswers()
{
	//Respuestas 
	//Arte // 0 - 19
	// 1st
	answers.push_back("A) Miguel Ángel"); // correcta
	answers.push_back("B) Donatello");
	answers.push_back("C) Leonardo da Vinci");
	answers.push_back("Francis Bacon");
	// 2nd 
	answers.push_back("A) Miguel Ángel Buonarroti"); // correcta
	answers.push_back("B) Leonardo Da Vinci");
	answers.push_back("C) Rafael Sanzio");
	answers.push_back("D) Galileo Galilei");
	// 3rd
	answers.push_back("A) El Gótico");
	answers.push_back("B) El barroco"); // correcta
	answers.push_back("C) el clasicismo");
	answers.push_back("D) Romanticismo");
	// 4th
	answers.push_back("A) Antropocentrismo");
	answers.push_back("B) Humanismo"); // correcta
	answers.push_back("C) Paradigma antropológico");
	answers.push_back("D) Teocentrismo");
	// 5th
	answers.push_back("A) Las tortugas ninjas"); // correcta
	answers.push_back("B) Los caballeros del Zodiaco");
	answers.push_back("C) Los cuatro fantásticos");
	answers.push_back("D) Los antagonistas de Attack Titan");

	//Politica // 20 - 39
	// 1st
	answers.push_back("A) Monarquía absoluta"); // correcta
	answers.push_back("B) Tiranía republicana");
	answers.push_back("C) Democracia participativa");
	answers.push_back("D) Liberalismo político");
	// 2nd
	answers.push_back("A) Toma de Constantinopla"); 
	answers.push_back("B) Tratado de paz de westfalia"); // correcta
	answers.push_back("C) Toma de la Bastilla");
	answers.push_back("D) La ruta de la seda");
	// 3rd
	answers.push_back("A) Clase media, baja y alta"); 
	answers.push_back("B) Nobleza, clero y estado llano"); // correcta
	answers.push_back("C) Artesanos, guardianes y gobernantes");
	answers.push_back("D) Publico, protegido y privado");
	// 4th
	answers.push_back("A) Tomás Moro"); 
	answers.push_back("B) Jean Bodín");
	answers.push_back("C) Nicolas Maquiavelo"); // correcta
	answers.push_back("D) Erasmo de Rotterdam.");
	// 5th
	answers.push_back("A) La Iglesia resalta su poder"); 
	answers.push_back("B) La Iglesia pierde el papel rector en la política"); // correcta
	answers.push_back("C) La Iglesia evangélica se posiciona en la política");
	answers.push_back("D) La política desaparece");
	
	//Ciencia // 40 - 59
	// 1st
	answers.push_back("A) Tomas Moro");
	answers.push_back("B) Galileo"); // correcta
	answers.push_back("C) Platón");
	answers.push_back("D) Arquimedes");
	// 2nd
	answers.push_back("A) Francis Bacon");
	answers.push_back("B) Galileo Galilei"); 
	answers.push_back(" C)Nicolas Maquiavelo"); // correcta
	answers.push_back("D) René Descartes");
	// 3rd
	answers.push_back("A) Isaac Newton");
	answers.push_back("B) René Descartes"); // correcta
	answers.push_back("C) Erasmo de Roterdam");
	answers.push_back("D) Francis Bacon");	
	// 4th
	answers.push_back("A) Aristóteles");
	answers.push_back("B) Nicolás Copérnico"); // correcta
	answers.push_back("C) Tomás de Aquino");
	answers.push_back("D) Isaac Newton");
	// 5th
	answers.push_back("A) El astrolabio");
	answers.push_back("B) La imprenta"); // correcta
	answers.push_back("C) La Nao y la Carabela");
	answers.push_back("D) El Telescopio");

	//Historia // 60 - 79
	// 1st
	answers.push_back("A) La monarquía");
	answers.push_back("B) El mercantilismo"); 
	answers.push_back("C) La burguesía"); // correcta
	answers.push_back("D) El proletariado");
	// 2nd
	answers.push_back("A) Grecia");
	answers.push_back("B) Inglaterra"); // correcta
	answers.push_back("C) Yugoslavia"); 
	answers.push_back("D) Egipto");
	// 3rd
	answers.push_back("A) Florencia-Napoli"); // correcta
	answers.push_back("B) Ámsterdam-Cracovia"); 
	answers.push_back("C) Reims-Colonia"); 
	answers.push_back("D) Milán-Lourdes");
	// 4th
	answers.push_back("A) Eslovaquia");
	answers.push_back("B) Estambul en Turquía"); // correcta
	answers.push_back("C) Mesopotamia");
	answers.push_back("D) Jerusalén");
	// 5th
	answers.push_back("A) La imprenta y la brújula"); // correcta
	answers.push_back("B) La rueda y la escritura"); 
	answers.push_back("C) Las máquinas de vapor y la producción en masa");
	answers.push_back("D) La pólvora y La rueda");	
}


