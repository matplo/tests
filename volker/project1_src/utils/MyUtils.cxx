#include "MyUtils.h"

#include <TH1F.h>
#include <TFile.h>
#include <TString.h>

// #include <iostream>
// using namespace std;

ClassImp(MyUtils)

MyUtils::MyUtils()
	: TNamed("MyUtils", "MyUtils")
	, fDummyMember(0)
	, fHdummy(0x0)
	, fFOut(0x0)
{
	Init();
}

MyUtils::MyUtils(const char *name, const char *title)
	: TNamed(name, title)
	, fDummyMember(0)
	, fHdummy(0x0)
	, fFOut(0x0)
{
	Init();
}

MyUtils::MyUtils(const char *name)
	: TNamed(name, "MyUtils")
	, fDummyMember(0)
	, fHdummy(0x0)
	, fFOut(0x0)
{
	Init();
}

MyUtils::~MyUtils()
{
	if (0x0 != fFOut)
	{
		fFOut->cd();
		fHdummy->Write();
		fFOut->Close();
	}
}

void MyUtils::Init()
{
	if (0x0 == fFOut)
	{
		TString foutname = TString::Format("%s.root", GetName());
		fFOut = new TFile(foutname.Data(), "RECREATE");
		fFOut->cd();
		fHdummy = new TH1F("fHdummy", GetName(), 100, -10, 10);
		fHdummy->Sumw2();
	}
}

void MyUtils::Loop(Int_t ntimes)
{
	fDummyMember = ntimes;
	for (Int_t i = 0; i < ntimes; i++)
	{
		fHdummy->FillRandom("gaus");
	}
}

