#ifndef CLOCKCALENDAR_H
#define CLOCKCALENDAR_H

class Data
{
	public:
	Data();
	~Data(){ };
	void coutAno();
	void coutMes();
	void coutDia();
	int getAno();
	int getMes();
	int getDia();
	void setAno(int);
	void setMes(int);
	void setDia(int);
	private:
	int ano, mes, dia;
};

Data::Data()
{
	ano = 1;
	mes = 1;
	dia = 1;
}
void Data::coutAno() {
	ano++;
}
void Data::coutMes() {
	if (mes < 11)
	mes++;
	else {
		Data::coutAno();
		mes = 1;
	}
}
void Data::coutDia() {
	if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) { //leap year
		if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
			if (dia < 30)
			dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
		}
		if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) {
			if (dia < 29)
			dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
		}
		if (mes == 2) {
			if (dia < 28)
			dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
		}
	}
	else {
		if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) {
			if (dia < 30)
			dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
		}
		if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) {
			if (dia < 29)
			dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
			
		}
		if (mes == 2)
		{
			if (dia < 27)
			dia++;
			else {
				Data::coutMes();
				dia = 1;
			}
		}
	}
}

int Data::getAno() {
	return ano;
}
int Data::getMes() {
	return mes;
}
int Data::getDia() {
	return dia;
}

void Data::setAno(int newAno) {
	ano = newAno;
}
void Data::setMes(int newMes) {
	mes = newMes;
}
void Data::setDia(int newDia) {
	dia = newDia;
}

class Hora : public Data
{
	public:
	Hora();
	~Hora() { };
	void coutHora();
	void coutMinuto();
	void coutSegundo();
	int getHora();
	int getMinuto();
	int getSegundo();
	void setHora(int);
	void setMinuto(int);
	void setSegundo(int);
	private:
	int hora, minuto, segundo;
};

Hora::Hora()
{
	hora = 0;
	minuto = 0;
	segundo = 0;
}

void Hora::coutHora() {
	if (hora < 23)
	hora++;
	else {
		Data::coutDia();
		hora = 0;
	}
}
void Hora::coutMinuto() {
	if (minuto < 59)
	minuto++;
	else {
		Hora::coutHora();
		minuto = 0;
	}
}
void Hora::coutSegundo() {
	if (segundo < 59)
	segundo++;
	else {
		Hora::coutMinuto();
		segundo = 0;
	}
}

int Hora::getHora() {
	return hora;
}
int Hora::getMinuto() {
	return minuto;
}
int Hora::getSegundo() {
	return segundo;
}

void Hora::setHora(int newHora) {
	hora = newHora;
}
void Hora::setMinuto(int newMinuto) {
	minuto = newMinuto;
}
void Hora::setSegundo(int newSegundo) {
	segundo = newSegundo;
}

class ClockCalendar: public Hora {
	
	public:
	void advance();
	void setCalendar(int newAno, int newMes, int newDia, int newHora,int newMinuto, int newSegundo);
};

void ClockCalendar::advance()
{
	Hora::coutSegundo();
}
void ClockCalendar::setCalendar(int newAno, int newMes, int newDia, int newHora,int newMinuto, int newSegundo)
{
	ClockCalendar::setAno(newAno);
	ClockCalendar::setMes(newMes);
	ClockCalendar::setDia(newDia);
	ClockCalendar::setHora(newHora);
	ClockCalendar::setMinuto(newMinuto);
	ClockCalendar::setSegundo(newSegundo);
}

#endif // ! CLOCKCALENDAR_H
