//Vanilla Banov Init.c
// Thank you for using my map
void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();
	
//Loot spawn Creator
//GetCEApi().ExportProxyData(vector.Zero, 100000); //Loot
//GetCEApi().ExportClusterData(); //Fruit	

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}
class CustomMission: MissionServer
{
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
		Class.CastTo(m_player, playerEnt);
		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	void addMags(PlayerBase player, string mag_type, int count)
	{
		if (count < 1)
			return;

		EntityAI mag;

		for (int i = 0; i < count; i++) {
			mag = player.GetInventory().CreateInInventory(mag_type);
		}

	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		
		player.GetInventory().CreateInInventory("Fingerless_Gloves_Wool_Black");
		player.GetInventory().CreateInInventory("BJJ_GI_Lower_Black");
		player.GetInventory().CreateInInventory("BJJ_GI_Upper_Black");
		player.GetInventory().CreateInInventory("Canvas_Backpack_Black");		
		player.GetInventory().CreateInInventory("Shemagh_Bandit_Black");		
		player.GetInventory().CreateInInventory("Kirza_Boots");
		player.GetInventory().CreateInInventory("SodaCan_Pipsi");
		player.GetInventory().CreateInInventory("SpaghettiCan");
		player.GetInventory().CreateInInventory("Banana");
		player.GetInventory().CreateInInventory("Apple");
		player.GetInventory().CreateInInventory("BandageDressing");


		}
};


Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
