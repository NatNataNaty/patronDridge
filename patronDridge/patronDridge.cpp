#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Canal {
public:
	int nro;
	string nombre;

	Canal(int nro, string nombre) : nro(nro), nombre(nombre) {}
};

class Pelicula {
public:
	string nombre;

	Pelicula(string nombre) : nombre(nombre) {}
};

// Abstraction
class Dispositivo {
public:
	virtual ~Dispositivo() {}

	virtual void cambiarCanal(int nro) = 0;
	virtual void aumentarVolumen() = 0;
	virtual void reducirVolumen() = 0;
	virtual void encender() = 0;
	virtual void apagar() = 0;
};

// Implementor 1
class TV : public Dispositivo {
public:
	int volumen;
	vector<Canal> canales;
	bool estado;
	string marca;
	int currentCanal;

	TV() {
		volumen = 100;
		estado = false;
		marca = "";
		currentCanal = 0;
	}

	void cambiarCanal(int nro) override {
		if (nro >= 0 && nro < canales.size()) {
			currentCanal = nro;
			cout << "Cambiando al canal: " << canales[nro].nombre << endl;
		}
		else {
			cout << "Canal no v�lido" << endl;
		}
	}

	void aumentarVolumen() override {
		if (volumen < 1000) {
			volumen += 100;
			cout << "Volumen aumentado. Volumen actual: " << volumen << endl;
		}
		else {
			cout << "Volumen m�ximo alcanzado" << endl;
		}
	}

	void reducirVolumen() override {
		if (volumen > 100) {
			volumen -= 100;
			cout << "Volumen reducido. Volumen actual: " << volumen << endl;
		}
		else {
			cout << "Volumen m�nimo alcanzado" << endl;
		}
	}

	void encender() override {
		estado = true;
		cout << "TV encendida" << endl;
	}

	void apagar() override {
		estado = false;
		cout << "TV apagada" << endl;
	}
};



// Implementor 2
class Radio : public Dispositivo {
public:
	int volumen;
	float canal;
	bool estado;

	Radio() {
		volumen = 50;
		canal = 88.0;
		estado = false;
	}

	void cambiarCanal(int nro) override {}

	void cambiarCanal(float canal) {
		this->canal = canal;
		cout << "Cambiando al canal: " << canal << endl;
	}

	void aumentarVolumen() override {
		if (volumen < 100) {
			volumen += 10;
			cout << "Volumen aumentado. Volumen actual: " << volumen << endl;
		}
		else {
			cout << "Volumen m�ximo alcanzado" << endl;
		}
	}

	void reducirVolumen() override {
		if (volumen > 0) {
			volumen -= 10;
			cout << "Volumen reducido. Volumen actual: " << volumen << endl;
		}
		else {
			cout << "Volumen m�nimo alcanzado" << endl;
		}
	}

	void encender() override {}

	void apagar() override {}
};
// Implementor 3
class TVBox : public Dispositivo {
public:
	int volumen;
	int servicioActual;
	string pelicula;
	string nombre;
	vector<Pelicula> listaPeliculas;

	TVBox(string nombre) : nombre(nombre) {
		volumen = 50;
		servicioActual = 1;
		pelicula = "";
	}

	void cambiarCanal(int nro) override {}

	void cambiarServicio(int servicio) {
		servicioActual = servicio;
		cout << "Cambiando al servicio: " << servicio << endl;
	}

	void reproducirPelicula(string nombrePelicula) {
		pelicula = nombrePelicula;
		cout << "Reproduciendo pel�cula: " << nombrePelicula << endl;
	}

	void aumentarVolumen() override {
		if (volumen < 100) {
			volumen += 10;
			cout << "Volumen aumentado. Volumen actual: " << volumen << endl;
		}
		else {
			cout << "Volumen m�ximo alcanzado" << endl;
		}
	}

	void reducirVolumen() override {
		if (volumen > 0) {
			volumen -= 10;
			cout << "Volumen reducido. Volumen actual: " << volumen << endl;
		}
		else {
			cout << "Volumen m�nimo alcanzado" << endl;
		}
	}

	void encender() override {}

	void apagar() override {}
};

int main() {
	// Ejemplo de uso de las clases

	// TV
	TV tv;
	tv.encender();
	tv.canales.push_back(Canal(1, "Canal 1"));
	tv.canales.push_back(Canal(2, "Canal 2"));
	tv.canales.push_back(Canal(3, "Canal 3"));
	tv.cambiarCanal(1);
	tv.aumentarVolumen();
	tv.reducirVolumen();
	tv.apagar();

	// Radio
	Radio radio;
	radio.encender();
	radio.cambiarCanal(90);
	radio.aumentarVolumen();
	radio.reducirVolumen();
	radio.apagar();

	// TVBox
	TVBox tvBox("Mi TVBox");
	tvBox.cambiarServicio(2);
	tvBox.reproducirPelicula("Avengers");
	tvBox.aumentarVolumen();
	tvBox.reducirVolumen();

	return 0;
}
