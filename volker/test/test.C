{
	MyUtils *ut = new MyUtils("called_from_ROOT");
	ut->Loop(50);
	delete ut;

	useUtils();
}
