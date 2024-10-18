;SDL
;Тут происходит выбор боеприпаса, если есть несколько вариантов. 
;Просто пишите по аналогии, заменяя название бп и номера форесайтов с учетом всех носителей этой ракеты.
;Учтите, что для работы некоторых ракет нужно электропитание на пусковой в момент пуска
;Если пусковая стреляет только одним типом ракет - в "launch_missile" ничего не пишется

;Пусковая с внешним питанием
(define "common_launcher"
	{if tagged "no_power" {spawn "%missile" inv_normal {tags add "no_power"}}
	else {spawn "%missile" inv_normal}}
)
;Многоствольная пусковая с внешним питанием
;Поддерживает 1 группу шутеров, при отсутствии шутеров стреляет с форесайта.
(define "multibarrel_launcher"
	{if name "00" 	{if tagged "no_power" {spawn "%missile" "%shooter00" x {tags add "no_power"}} else {spawn "%missile" "%shooter00" x}}
	else name "01"  {if tagged "no_power" {spawn "%missile" "%shooter01" x {tags add "no_power"}} else {spawn "%missile" "%shooter01" x}}
	else name "02" 	{if tagged "no_power" {spawn "%missile" "%shooter02" x {tags add "no_power"}} else {spawn "%missile" "%shooter02" x}}
	else name "03" 	{if tagged "no_power" {spawn "%missile" "%shooter03" x {tags add "no_power"}} else {spawn "%missile" "%shooter03" x}}
	else name "04" 	{if tagged "no_power" {spawn "%missile" "%shooter04" x {tags add "no_power"}} else {spawn "%missile" "%shooter04" x}}
	else name "05" 	{if tagged "no_power" {spawn "%missile" "%shooter05" x {tags add "no_power"}} else {spawn "%missile" "%shooter05" x}}
	else name "06" 	{if tagged "no_power" {spawn "%missile" "%shooter06" x {tags add "no_power"}} else {spawn "%missile" "%shooter06" x}}
	else name "07" 	{if tagged "no_power" {spawn "%missile" "%shooter07" x {tags add "no_power"}} else {spawn "%missile" "%shooter07" x}}
	else {if tagged "no_power" {spawn "%missile" inv_normal {tags add "no_power"}}	else {spawn "%missile" inv_normal}}
	}
)
(define "check_weapon_ammo"
	;Конкурсы имеют собственное питание (т.к. съемные) и от внешнего не зависят.
		{if  ammo_tag_for_weapon "%weapon_place" "9m111 ammo" 				("multibarrel_launcher" missile(9k111_carrier) shooter(shooter_))
		else ammo_tag_for_weapon "%weapon_place" "9m111m ammo" 				("multibarrel_launcher" missile(9k111m_carrier) shooter(shooter_))
		else ammo_tag_for_weapon "%weapon_place" "9m113 ammo" 				("multibarrel_launcher" missile(9k113_carrier) shooter(shooter_))
		else ammo_tag_for_weapon "%weapon_place" "9m113m ammo" 				("multibarrel_launcher" missile(9k113m_carrier) shooter(shooter_))
		else ammo_tag_for_weapon "%weapon_place" "9m113m1 ammo" 			("multibarrel_launcher" missile(9k113m1_carrier) shooter(shooter_))
		else ammo_tag_for_weapon "%weapon_place" "hj73c ammo" 					("multibarrel_launcher" missile(hj73c_carrier) shooter(shooterr_))
		else ammo_tag_for_weapon "%weapon_place" "hj-10 hj-10b ammo" 			("multibarrel_launcher" missile(red_arrow_10b_carrier) shooter(shooter))
		else ammo_tag_for_weapon "%weapon_place" "9k115-2 cm_e ammo" 			("common_launcher" missile(9k115-1_cm_carrier))
		else ammo_tag_for_weapon "%weapon_place" "9k115-2 cm ammo" 			("common_launcher" missile(9k115-2_cm_carrier))
		else ammo_tag_for_weapon "%weapon_place" "bullet100a_RUS rok ammo"		("common_launcher" missile(9m117_carrier))
		else ammo_tag_for_weapon "%weapon_place" "bullet100a_RUS_h rok ammo"	("common_launcher" missile(9m117m_carrier))
		else ammo_tag_for_weapon "%weapon_place" "bullet115_RUS rok ammo"		("common_launcher" missile(9m117_115_carrier))
		else ammo_tag_for_weapon "%weapon_place" "bullet105_cn rok ammo"		("common_launcher" missile(9m117cn_carrier))
		else ammo_tag_for_weapon "%weapon_place" "bullet100_cn_rapira rok ammo"	("common_launcher" missile(9m117cn100_carrier))
		else ammo_tag_for_weapon "%weapon_place" "bullet125_h_rus rok ammo"	("common_launcher" missile(9m119m1_carrier))
		else ammo_tag_for_weapon "%weapon_place" "bullet125_m_rus rok ammo"	("common_launcher" missile(9m119m_carrier))
		else ammo_tag_for_weapon "%weapon_place" "bullet125_RUS rok ammo" 		("common_launcher" missile(reflex_carrier))
		else ammo_tag_for_weapon "%weapon_place" "tow_rock ammo"				("common_launcher" missile(tow_carrier))
		else ammo_tag_for_weapon "%weapon_place" "tow2b ammo"					("common_launcher" missile(tow2b_carrier))
		else ammo_tag_for_weapon "%weapon_place" "tow2d ammo"					("common_launcher" missile(tow2d_carrier))
		else ammo_tag_for_weapon "%weapon_place" "tow2e ammo"					("common_launcher" missile(tow2e_carrier))
		else ammo_tag_for_weapon "%weapon_place" "tow2_fg ammo"				("common_launcher" missile(tow2_fg_carrier))
		else ammo_tag_for_weapon "%weapon_place" "hj8e ammo"					("common_launcher" missile(hj8e_carrier))
		else ammo_tag_for_weapon "%weapon_place" "hj8h ammo"					("common_launcher" missile(hj8h_carrier))
		else ammo_tag_for_weapon "%weapon_place" "hj8f ammo"					("common_launcher" missile(hj8f_carrier))
		else ammo_tag_for_weapon "%weapon_place" "milan_rock ammo"				("common_launcher" missile(milan_rock_carrier))
		else ammo_tag_for_weapon "%weapon_place" "milan-er ammo"				("common_launcher" missile(milan-er_carrier))
		else ammo_tag_for_weapon "%weapon_place" "spike-er2 ammo"				("common_launcher" missile(spike-er2_carrier))
		else ammo_tag_for_weapon "%weapon_place" "spike-er ammo"				("common_launcher" missile(spike-er_carrier))
		else ammo_tag_for_weapon "%weapon_place" "9m133 cm_e ammo"				("common_launcher" missile(9m133_cm_carrier))
		else ammo_tag_for_weapon "%weapon_place" "9m133 cm ammo"				("common_launcher" missile(9m133_1_cm_carrier))
		else ammo_tag_for_weapon "%weapon_place" "9m133 fg ammo"				("common_launcher" missile(9m133_fg_carrier))
		else ammo_tag_for_weapon "%weapon_place" "9m133 tb ammo"				("common_launcher" missile(9m133_tb_carrier))
		else ammo_tag_for_weapon "%weapon_place" "shershen cm ammo"			("common_launcher" missile(shershen_ammo_cm_carrier))
		else ammo_tag_for_weapon "%weapon_place" "shershen fg ammo"			("common_launcher" missile(shershen_ammo_fg_carrier))
		else ammo_tag_for_weapon "%weapon_place" "lahat ammo"					("common_launcher" missile(lahat_carrier))
		else ammo_tag_for_weapon "%weapon_place" "spike_nlos cm ammo"
			{if props "exactor_mk2"
				("multibarrel_launcher" missile(spike_nlos_carrier) shooter(shooter))
			else flag "ptur1"	;вертолет, левая ПУ
				("multibarrel_launcher" missile(spike_nlos_carrier) shooter(shooter_l))
			else flag "ptur2"	;вертолет, правая ПУ
				("multibarrel_launcher" missile(spike_nlos_carrier) shooter(shooter_r))
			else ("common_launcher" missile(spike_nlos_carrier))
			}										
		else ammo_tag_for_weapon "%weapon_place" "spike_nlos fg ammo"
			{if props "exactor_mk2"
				("multibarrel_launcher" missile(spike_nlos_fg_carrier) shooter(shooter))
			else flag "ptur1"	;вертолет, левая ПУ
				("multibarrel_launcher" missile(spike_nlos_fg_carrier) shooter(shooter_l))
			else flag "ptur2"	;вертолет, правая ПУ
				("multibarrel_launcher" missile(spike_nlos_fg_carrier) shooter(shooter_r))
			else ("common_launcher" missile(spike_nlos_fg_carrier))
			}										
		else ammo_tag_for_weapon "%weapon_place" "agm-114 k ammo"
			{if props "mq9"							("multibarrel_launcher" missile(agm-114k_carrier) shooter(hellfire_shooter_))
			else props "shorad"						("multibarrel_launcher" missile(agm-114k_carrier) shooter(shooterl))
			else									("common_launcher" missile(agm-114k_carrier))
			}										
		else ammo_tag_for_weapon "%weapon_place" "agm-114 k2 ammo"
			{if props "mq9"							("multibarrel_launcher" missile(agm-114k2_carrier) shooter(hellfire_shooter_))
			else props "shorad"						("multibarrel_launcher" missile(agm-114k2_carrier) shooter(shooterl))
			else									("common_launcher" missile(agm-114k2_carrier))
			}										
		else ammo_tag_for_weapon "%weapon_place" "agm-114 l ammo"
			{if props "mq9"							("multibarrel_launcher" missile(agm-114l_carrier) shooter(hellfire_shooter_))
			else props "shorad"						("multibarrel_launcher" missile(agm-114l_carrier) shooter(shooterl))
			else									("common_launcher" missile(agm-114l_carrier))
			}										
		else ammo_tag_for_weapon "%weapon_place" "agm-114 n ammo"
			{if props "mq9"							("multibarrel_launcher" missile(agm-114n_carrier) shooter(hellfire_shooter_))
			else props "shorad"						("multibarrel_launcher" missile(agm-114n_carrier) shooter(shooterl))
			else									("common_launcher" missile(agm-114n_carrier))
			}										
		else ammo_tag_for_weapon "%weapon_place" "agm-114 r ammo"
			{if props "mq9"							("multibarrel_launcher" missile(agm-114r_carrier) shooter(hellfire_shooter_))
			else props "shorad"						("multibarrel_launcher" missile(agm-114r_carrier) shooter(shooterl))
			else									("common_launcher" missile(agm-114r_carrier))
			}										
		else ammo_tag_for_weapon "%weapon_place" "brimstone ammo"				("multibarrel_launcher" missile(brimstone_carrier) shooter(brimstone_shooter_))
		else ammo_tag_for_weapon "%weapon_place" "trigat ammo"					("common_launcher" missile(trigat_carrier))
		else ammo_tag_for_weapon "%weapon_place" "akd-10 ammo"					("common_launcher" missile(akd-10_carrier))
		else ammo_tag_for_weapon "%weapon_place" "strela10 9m37 ammo"			("multibarrel_launcher" missile(9k37_carrier) shooter(shooter))
		else ammo_tag_for_weapon "%weapon_place" "strela10 9m333 ammo"			("multibarrel_launcher" missile(9k333_carrier) shooter(shooter))
		else ammo_tag_for_weapon "%weapon_place" "9m38 buk ammo"				("multibarrel_launcher" missile(9m38_carrier) shooter(shooter))
		else ammo_tag_for_weapon "%weapon_place" "9m317 buk ammo"				("multibarrel_launcher" missile(9m317_carrier) shooter(shooter))
		else ammo_tag_for_weapon "%weapon_place" "hq16 hq16a ammo"				("multibarrel_launcher" missile(hq16a_missile_carrier) shooter(shooter))
		else ammo_tag_for_weapon "%weapon_place" "hq16 hq16b ammo"				("multibarrel_launcher" missile(hq16b_missile_carrier) shooter(shooter))
		else ammo_tag_for_weapon "%weapon_place" "jav_rock f ammo"
			{spawn "proj_actorprobe" inv_normal {spawn "javf_rock_carrier" "missile_point15"   x}}
		else ammo_tag_for_weapon "%weapon_place" "javf_rock ammo"
			{spawn "proj_actorprobe" inv_normal {spawn "javf_rock_carrier" "missile_point15"   x}}
		else ammo_tag_for_weapon "%weapon_place" "jav_rock ammo"
			{spawn "proj_actorprobe" inv_normal {spawn "jav_rock_carrier" "missile_point15"   x}}
		else ammo_tag_for_weapon "%weapon_place" "9m114m fg ammo"				("common_launcher" missile(9m114f_carrier))
		else ammo_tag_for_weapon "%weapon_place" "9m114m cm ammo"				("common_launcher" missile(9m114m_carrier))
		else ammo_tag_for_weapon "%weapon_place" "9m120 fg ammo"				
			{if props "t-15_au220"	("multibarrel_launcher" missile(9m120f_carrier) shooter(shooterar_))
			else props "bmpt" and flag "gun2"	("multibarrel_launcher" missile(9m120f_carrier) shooter(shooterl_))
			else props "bmpt" and flag "gun3"	("multibarrel_launcher" missile(9m120f_carrier) shooter(shooterr_))
			else ("multibarrel_launcher" missile(9m120f_carrier) shooter(shooter_ataka))
			}
		else ammo_tag_for_weapon "%weapon_place" "9m120 cm ammo"
			{if props "t-15_au220"	("multibarrel_launcher" missile(9m120m_carrier) shooter(shooterar_))
			else props "bmpt" and flag "gun2"	("multibarrel_launcher" missile(9m120m_carrier) shooter(shooterl_))
			else props "bmpt" and flag "gun3"	("multibarrel_launcher" missile(9m120m_carrier) shooter(shooterr_))
			else ("multibarrel_launcher" missile(9m120m_carrier) shooter(shooter_ataka))
			}
		else ammo_tag_for_weapon "%weapon_place" "sm_2er_blockiv aegis ammo"
				 {delay 0.03 {call "launch_sm_2"} } 
		else ammo_tag_for_weapon "%weapon_place" "tomahawk aegis ammo"
				 {delay 0.03 {call "launch_tomahawk"} } 
		else ammo_tag_for_weapon "%weapon_place" "asroc_vla aegis ammo"
				 {delay 0.03 {call "launch_asroc"} } 
		else ammo_tag_for_weapon "%weapon_place" "tur_kobra ammo"				("common_launcher" missile(tur_kobra_carrier))
		else ammo_tag_for_weapon "%weapon_place" "tur_kombat ammo"				("common_launcher" missile(tur_kombat_carrier))
		else ammo_tag_for_weapon "%weapon_place" "53_65k_torpedo"
			{if flag "torpedo1"				("multibarrel_launcher" missile(53_65k_torpedo_spawner) shooter(shooter_0))
			else flag "torpedo2"			("multibarrel_launcher" missile(53_65k_torpedo_spawner) shooter(shooterb_0))
			else flag "gun2"				("multibarrel_launcher" missile(53_65k_torpedo_spawner) shooter(shooter_0))
			}										
		else ammo_tag_for_weapon "%weapon_place" "vodopad"
			{if flag "torpedo1"				("multibarrel_launcher" missile(vodopad_sub_helper) shooter(shooter_0))
			else flag "torpedo2"			("multibarrel_launcher" missile(vodopad_sub_helper) shooter(shooterb_0))
			else flag "gun2"				("multibarrel_launcher" missile(vodopad_sub_helper) shooter(shooter_0))
			}										
		else ammo_tag_for_weapon "%weapon_place" "3m14 caliber 533torpedo_rus"
			{if flag "torpedo1"				("multibarrel_launcher" missile(caliber_sub_helper) shooter(shooter_0))
			else flag "torpedo2"			("multibarrel_launcher" missile(caliber_sub_helper) shooter(shooterb_0))
			}										
		else ammo_tag_for_weapon "%weapon_place" "3m54 caliber 533torpedo_rus"
			{if flag "torpedo1"				("multibarrel_launcher" missile(caliber54_sub_helper) shooter(shooter_0))
			else flag "torpedo2"			("multibarrel_launcher" missile(caliber54_sub_helper) shooter(shooterb_0))
			}										
		else ammo_tag_for_weapon "%weapon_place" "mk48_torpedo"
			{if flag "torpedo1"				("multibarrel_launcher" missile(mk48_torpedo_spawner) shooter(shootera_))
			else flag "torpedo2"			("multibarrel_launcher" missile(mk48_torpedo_spawner) shooter(shooterb_))
			}										
		else ammo_tag_for_weapon "%weapon_place" "ugm-84a"
			{if flag "torpedo1"				("multibarrel_launcher" missile(harpoon_sub_helper) shooter(shootera_))
			else flag "torpedo2"			("multibarrel_launcher" missile(harpoon_sub_helper) shooter(shooterb_))
			}										
		else ammo_tag_for_weapon "%weapon_place" "shahed136 base ammo"	
				{if name "00" {delay 0.1 {spawn "shahed136_base" "shooter00" x no_normal no_position {tags add "drone00"}} } 
				else name "01" {delay 0.1 {spawn "shahed136_base" "shooter01" x no_normal no_position {tags add "drone01"}} } 
				else name "02" {delay 0.1 {spawn "shahed136_base" "shooter02" x no_normal no_position {tags add "drone02"}} } 
				else name "03" {delay 0.1 {spawn "shahed136_base" "shooter03" x no_normal no_position {tags add "drone03"}} } 
				else name "04" {delay 0.1 {spawn "shahed136_base" "shooter04" x no_normal no_position {tags add "drone04"}} } 
				}
		else ammo_tag_for_weapon "%weapon_place" "lancet3m fg ammo"			{tags add "lancet3m_fg"}
		else ammo_tag_for_weapon "%weapon_place" "lancet3m cm ammo"			{tags add "lancet3m_cm"}

		else ammo_tag_for_weapon "%weapon_place" "bullet152_usa rok ammo"		("common_launcher" missile(shillelagh_carrier))
		else ammo_tag_for_weapon "%weapon_place" "bullet152_rus korr ammo"		("common_launcher" missile(krasnopol_test))
		
	;этот блок трогать не нужно, он вызывается только если не ракета.

		else ammo_tag_for_weapon "%weapon_place" "ammo cm supertandem"	{spawn "cw_cumshassist_spawner_3gen" inv_normal}
		else ammo_tag_for_weapon "%weapon_place" "ammo cm tandem"		{spawn "cw_cumshassist_spawner_2gen" inv_normal}
		else ammo_tag_for_weapon "%weapon_place" "ammo cm"				{spawn "cw_cumshassist_spawner_1gen" inv_normal}
		else ammo_tag_for_weapon "%weapon_place" "ammo fg"				{spawn "cw_fgshassist_spawner" inv_normal}
		else ammo_tag_for_weapon "%weapon_place" "ammo apcr"				{spawn "cw_apcrshassist_spawner" inv_normal}
		}
		{set "%weapon_place" 0}

)
{on "proj_probe"
	{if flag "gun" ("check_weapon_ammo" weapon_place(gun))
	else flag "gun2" ("check_weapon_ammo" weapon_place(gun2))
	else flag "gun3" ("check_weapon_ammo" weapon_place(gun3))
	else flag "ptur" ("check_weapon_ammo" weapon_place(ptur))
	else flag "ptur1" ("check_weapon_ammo" weapon_place(ptur1))
	else flag "ptur2" ("check_weapon_ammo" weapon_place(ptur2))
	else flag "ptur3" ("check_weapon_ammo" weapon_place(ptur3))
	else flag "ptur4" ("check_weapon_ammo" weapon_place(ptur4))
	else flag "ptur5" ("check_weapon_ammo" weapon_place(ptur5))
	else flag "ptur6" ("check_weapon_ammo" weapon_place(ptur6))
	else flag "torpedo1" ("check_weapon_ammo" weapon_place(torpedo1))
	else flag "torpedo2" ("check_weapon_ammo" weapon_place(torpedo2))
	}
}
