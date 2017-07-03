struct monster//怪物结构体的定义 
{
	int lv;
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
	char infor[100];//人物简介
	int skill[20];//技能开关
	int area;//地区限定
	int flee;//逃跑几率
	int crit;//基础暴击几率 
	int dodge;//基础闪避几率 
};
