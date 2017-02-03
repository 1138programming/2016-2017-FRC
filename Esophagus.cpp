#include <Subsystems/Esophagus.h>

Esophagus::Esophagus() :

Subsystem("Esophagus")
{
	// TODO Auto-generated constructor stub
	esoSolenoid = new Solenoid(0);


}

void Esophagus::InitDefaultCommand()
{

}

void Esophagus::MoveEsophagusToGearCollection() //This function moves the Esophagus so that it can now collect gears
{
	esoSolenoid->Set(false);
}

void Esophagus::MoveEsophagusToBallCollection() //This function moves the Esophagus so that it can now collect balls
{
	esoSolenoid->Set(true);
}

void Esophagus::ShiftGearBallCollection() //This function moves the Esophagus so that it switches between collecting balls and gears
{
	esoSolenoid->Get();
	if (esoSolenoid != false)
		{
			MoveEsophagusToGearCollection();
		}
		else
		{
			MoveEsophagusToBallCollection();
		}
}
