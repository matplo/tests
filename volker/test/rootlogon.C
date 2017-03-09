{
	TString libs[] =
	{
		"../lib/libMyUtils.dylib",
		"null"
	};

	Int_t i = 0;
	while (libs[i] != "null")
	{
		Int_t retval = gSystem->Load(libs[i]);
		cout << "[i] loaded... " << libs[i] << " " << retval << endl;
		i++;
	}
}
