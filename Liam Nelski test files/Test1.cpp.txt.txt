#include <iostream>
#include "prescription.hpp"
//adding the project namespace (you may modify the line below)
using namespace medical;
//function prototypes
//implemented by your professor
std::vector<Prescription*>* CreatePrescription();
//partially implemented by your professor
void TestDrug();
//5 marks for the implementation
std::vector<Prescription*> FindDrug(std::vector<Prescription*>*
	perscriptions, std::string otc_name);
//5 marks for the implementation
std::vector<Prescription*> FindPatient(std::vector<Prescription*>*
	perscriptions, std::string patient);
//5 marks for the implementation
std::vector<Prescription*> FindDoctor(std::vector<Prescription*>*
	perscriptions, std::string doctor);
int main()
{
	TestDrug();
}
void TestDrug()
{
	auto perscriptions = *CreatePrescription();

	int counter = 1;
	std::cout << "************ All perscriptions\n";
	for (int i = 0; i < perscriptions.size(); i++)
	{
		Prescription* prescription = perscriptions[i];

		std::cout << std::to_string(i + counter) + ". Patient:" << prescription->GetPatient()
			<< " (Dr." << prescription->GetDocter() << ")\n"
			<< *prescription << "\n\n";
	}
	//4 marks - prints 9 perscriptions


	std::string name = "Clinton"; //name of doctor
	counter = 1;
	std::cout << "************ perscriptions by " << name << "\n";
	for (int i = 0; i < perscriptions.size(); i++)
	{
		Prescription* prescription = perscriptions[i];

		if (prescription->GetDocter() == name)
		{
			std::cout << std::to_string(i + counter) + ". " << prescription->GetPatient()
				<< " (Dr." << prescription->GetDocter() << ")\n"
				<< *prescription << "\n";

		}

	}
	//3 marks - prints 3 perscriptions


	name = "Martin"; //name of patient
	counter = 1;
	std::cout << "************ perscriptions for " << name << "\n";
	for (int i = 0; i < perscriptions.size(); i++)
	{
		Prescription* prescription = perscriptions[i];

		if (prescription->GetPatient() == name)
		{
			std::cout << std::to_string(i + counter) + ". " << prescription->GetPatient()
				<< " (Dr." << prescription->GetDocter() << ")\n"
				<< *prescription << "\n";

		}

	}
	//3 marks - prints 3 perscriptions

	// Can't be done? the name of the drug is unaccessable unless its being printed?
	// 
	// 
	//name = "tylenol"; //name of drug
	//counter = 1;
	//std::cout << "************ perscriptions with " << name << "\n";
	//for (int i = 0; i < perscriptions.size(); i++)
	//{
	//	Prescription* prescription = perscriptions[i];
	//	//if (hasDrug)
	//	//{
	//		std::cout << std::to_string(i + counter) + ". " << prescription->GetPatient()
	//			<< " (Dr." << prescription->GetDocter() << ")\n"
	//			<< *prescription << "\n";
	//	//}
	//}
	//3 marks - prints 5 perscriptions


	counter = 1;
	std::cout << "************ Deleting perscriptions" << "\n";
	// Loop through all Prescriptions
	for (int i = 0; i < perscriptions.size(); i++)
	{
		Prescription* prescription = perscriptions[i];
		 
		// Loop Through Drugs and Delete them
		for (int k = 0; k < prescription->GetDrugs().size(); k++)
		{
			delete prescription->GetDrugs()[k];
		}

	}
	//3 marks – deletes all the drugs in all the perscriptions
}
std::vector<Prescription*>* CreatePrescription()
{
	//testing the drug class
	DrugInfo info;
	info.duration = 21;
	info.unit = "capsule";
	info.quantity = 3;
	DrugInfo tylenol = info;
	tylenol.name = "acetaminophen";
	tylenol.otc_name = "tylenol";
	DrugInfo advil = info;
	advil.name = "ibuprofen";
	advil.otc_name = "advil";
	DrugInfo claritin = info;
	claritin.name = "loratadine";
	claritin.otc_name = "claritin";
	DrugInfo zantac = info;
	zantac.name = "ranitidine";
	zantac.otc_name = "zantac";
	DrugInfo zocor = info;
	zocor.name = "simvastatin";
	zocor.otc_name = "zocor";
	DrugInfo lipitor = info;
	lipitor.name = "atorvastatin";
	lipitor.otc_name = "lipitor";
	DrugInfo prilosec = info;
	prilosec.name = "omeprazole";
	prilosec.otc_name = "prilosec";
	info.quantity = 1;
	DrugInfo metformin = info;
	metformin.name = "glucophage";
	metformin.otc_name = "metformin";
	DrugInfo synthroid = info;
	synthroid.name = "levothyroxine";
	synthroid.otc_name = "synthroid";
	DrugInfo robitussin = info;

	robitussin.unit = "teaspoon";
	robitussin.quantity = 2;
	robitussin.duration = 14;
	robitussin.name = "dextromethorphan";
	robitussin.otc_name = "robitussin";
	//creating some perscriptions
	Prescription* trudeau = new Prescription("Biden", "Trudeau");
	Prescription* harper = new Prescription("Trump", "Harper");
	Prescription* martin = new Prescription("Obama", "Martin");
	Prescription* chretien = new Prescription("Bush", "Chretien");
	Prescription* campbell = new Prescription("Clinton", "Campbell");
	Prescription* mulroney = new Prescription("Bush", "Mulroney");
	Prescription* martin1 = new Prescription("Carter", "Martin");
	Prescription* clark = new Prescription("Clinton", "Clark");
	Prescription* martin2 = new Prescription("Clinton", "Martin");
	//add some drugs to some of the perscriptions
	harper->AddDrug(Drug::CreateDrug(tylenol));
	harper->AddDrug(Drug::CreateDrug(robitussin));
	harper->AddDrug(Drug::CreateDrug(claritin));
	trudeau->AddDrug(Drug::CreateDrug(synthroid));
	trudeau->AddDrug(Drug::CreateDrug(robitussin));
	trudeau->AddDrug(Drug::CreateDrug(zantac));
	trudeau->AddDrug(Drug::CreateDrug(advil));
	trudeau->AddDrug(Drug::CreateDrug(claritin));
	martin->AddDrug(Drug::CreateDrug(prilosec));
	martin->AddDrug(Drug::CreateDrug(tylenol));
	martin1->AddDrug(Drug::CreateDrug(advil));
	martin2->AddDrug(Drug::CreateDrug(synthroid));
	chretien->AddDrug(Drug::CreateDrug(prilosec));
	chretien->AddDrug(Drug::CreateDrug(metformin));
	mulroney->AddDrug(Drug::CreateDrug(advil));
	mulroney->AddDrug(Drug::CreateDrug(tylenol));
	clark->AddDrug(Drug::CreateDrug(lipitor));
	clark->AddDrug(Drug::CreateDrug(tylenol));
	campbell->AddDrug(Drug::CreateDrug(tylenol));
	//allocate memory for a vector that will store pointers to prescription
	std::vector<Prescription*>* perscriptions = new
		std::vector<Prescription*>();
	perscriptions->push_back(harper);
	perscriptions->push_back(trudeau);
	perscriptions->push_back(martin);
	perscriptions->push_back(martin1);
	perscriptions->push_back(martin2);
	perscriptions->push_back(chretien);
	perscriptions->push_back(campbell);
	perscriptions->push_back(mulroney);
	perscriptions->push_back(clark);
	return perscriptions;
}