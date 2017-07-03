struct state//人物状态结构体的定义 
{
	int lv;//级数 
	int exp;//经验值 
	int expmax;//经验最大值 
	char name[10];//名字 
	int hp;//当前血量 
	int hpmax;//最大血量 
	int mp;//当前魔法值 
	int mpmax;//最大魔法值 
	int strength;//力量（影响物理攻击） 
	int physique;//体质（影响防御与最大血量） 
	int agile;//敏捷（影响出手速度与回避几率暴击几率） 
	int mentality;//智力（影响魔法攻击与魔法防御）
	char infor[100];//人物简介
	int head;//头部装备 
	int foot;//脚部装备 
	int body;//身体装备 
	int weapon;//武器装备 
	int leg;//腿部装备 
	int skill[20];//技能开关
	int crit;//基础暴击几率 
	int dodge;//基础闪避几率 
};
