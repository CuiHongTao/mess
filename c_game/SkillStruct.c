struct skill//技能结构体的定义 
{
	char name[10];//技能名 
	enum {monster,own} type;//对象 
	int basis;//基础伤害 
	float promote;//加成 
	int expend;//花费 
	char infor[100];//信息 
};
