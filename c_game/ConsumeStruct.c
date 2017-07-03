struct consume//消耗品结构体的定义 
{
	int lv;//级数 
	int exp;//经验值 
	char name[10];//名字 
	int hp;//当前血量 
	int hpmax;//最大血量 
	int mp;//当前魔法值 
	int mpmax;//最大魔法值 
	int strength;//力量（影响物理攻击） 
	int physique;//体质（影响防御与最大血量）
	int agile;//敏捷（影响出手速度与回避几率暴击几率） 
	int mentality;//智力（影响魔法攻击与魔法防御）
	int number;//物品的数量 
	int flag; 
	char infor[100];
};
