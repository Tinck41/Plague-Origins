struct Inventory 
{
	Inventory(int essence) 
	{
		this->essence = essence;
	}
	int essence;
	int state = 0;
};