#ifndef MYUTILS_HH
#define MYUTILS_HH

#include <TNamed.h>
class TH1F;
class TFile;

class MyUtils : public TNamed
{
	public:
		MyUtils();
		MyUtils(const char *name);
		MyUtils(const char *name, const char *title);
		virtual ~MyUtils();
		virtual void Loop(Int_t ntimes = 10);

	protected:
		virtual void Init();

	private:

		Int_t    fDummyMember;
		TH1F    *fHdummy; //!
		TFile   *fFOut; //!

	ClassDef(MyUtils, 0)
};

#endif // MYUTILS_HH
