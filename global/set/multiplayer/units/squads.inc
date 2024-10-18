;SDL
;------------------------------------------------------------------------------
;	Содержимое content поля:
; 		content поле содержит список unitId (bread или entity). 
;		Символ ':' после unitId указывает на количество юнитов данного типа.
;		Символ '*' указывает на id текущего блока юнита. 
;		Юниты в круглых скобках будут посажены(прилинкованы) к юниту указанному перед '(' скобкой.
;		Спец символы '*','(',')' обязательно должны быть окружены пробелами!
;		Первый в списке юнит становиться командиром. 
;------------------------------------------------------------------------------

;=========================== SET =============================


(define "squad"
	{"%name(%side)"
		{content "%squadcontent"}
		{tags "squad all frontline_cp squad infantry %side %t %name_%side"}
		{fore 1}
		{info "%info(%side)"}
		{level 1}
		{spawn_distance 500}
		{auto_recovering_time 60}
	}
)
(define "s_squad"
	{"%name(%side)"
		{content "%squadcontent"}
		{tags "squad all frontline_cp squad infantry %side %t %name_%side"}
		{fore 1}
		{info "%info(%side)"}
		{level 1}
		{spawn_distance 100}
		{not_for_sale}
		{actions "worker"}
		{inventory %inv}
	}
)
;========================== SQUADS ============================

;========================== rus ============================
;===============================общие войска=========================================== 
("squad" side(rus) t(all) name(bazookers2) info(bazookers2) squadcontent(mp2/rus/bazooker2:1 mp2/rus/bazooker2_help:1))
("squad" side(rus) t(all) name(pzrk) info(pzrk) squadcontent(mp2/rus/pzrk:1 mp2/rus/pzrkhelp:1))
("squad" side(rus) t(all) name(mso) info(mso) squadcontent(mp2/rus/mso_com:1 mp2/rus/mso_mgun:1 mp2/rus/mso_mgunhelp:1 mp2/rus/mso_rpg:1 mp2/rus/mso_rpghelp:1 mp2/rus/mso_smg2:2))
;===============================Вспомогательные войска=========================================== supl
("squad" side(rus) t(all) name(tankman) info(tankman) squadcontent(mp2/rus/tankman:1))
("squad" side(rus) t(all) name(vehicle_supporter) info(vehicle_supporter) squadcontent(mp2/rus/vehicle_supporter:2))
("squad" side(rus) t(all) name(pilot) info(pilot) squadcontent(mp2/rus/pilot:1))
("s_squad" side(rus) t(all transfer_forbiden) name(uni_miners) info(uni_miners) squadcontent(mp2/rus/universal_miner:5)
inv(
	{item "mine antipersonnel_pob" {count 40} {regeneration_time 990}} 
	{item "mine antitank_tm89" {count 25} {regeneration_time 990}}
	)
)
("s_squad" side(rus) t(all transfer_forbiden) name(engineers) info(engineers) squadcontent(mp2/rus/engineer:5)
inv(
		{item "barbwire_kit" {count 15} {regeneration_time 495}} ; 1 items will be regenerated for 165sec
		{item "hedgehog_kit" {count 20} {regeneration_time 660}}
		{item "sandbag_kit" {count 20} {regeneration_time 440}}
		{item "dot_wood_kit" {count 3} {regeneration_time 1240}}
		{item "blindage_wood_kit" {count 1} {regeneration_time 1240}}
		{item "supp_point_kit" {count 1} {regeneration_time 1240}}
	)
)
("s_squad" side(rus) t(all transfer_forbiden) name(corpsman) info(corpsman) squadcontent(mp2/rus/corpsman:1) inv())
;===============================ВВС===========================================
;===============================ПВО===========================================
;===============================Артиллеристы===========================================
("squad" side(rus) t(all) name(sappers) info(sappers) squadcontent(mp2/rus/saper:1))
("squad" side(rus) t(all) name(spotters) info(spotters) squadcontent(mp2/rus/gru_com_art:1 mp2/rus/gru_com_art:1 mp2/rus/gru_com_art:1))
;===============================Мотострелки===========================================
("squad" side(rus) t(all) name(mot) info(mot) squadcontent(mp2/rus/spec_com:1 mp2/rus/spec_mgun:1 mp2/rus/spec_mgunhelp:1 mp2/rus/spec_rpg:1 mp2/rus/spec_rpghelp:1 mp2/rus/spec_zamcom:1 mp2/rus/spec_smg2:1))
("squad" side(rus) t(all) name(elite) info(elite) squadcontent(mp2/rus/gru_com:1 mp2/rus/gru_mgun2:1 mp2/rus/gru_mgun:1 mp2/rus/gru_smg3:1 mp2/rus/gru_rpg:1 mp2/rus/gru_rpghelp:1 mp2/rus/gru_smg2:1 mp2/rus/gru_smg:1 mp2/rus/gru_sniper:1 mp2/rus/gru_zamcom:1))
("squad" side(rus) t(all) name(snipers2) info(snipers2) squadcontent(mp2/rus/motostrelk_sniper:1 mp2/rus/motostrelk_spotter:1))
("squad" side(rus) t(all) name(at_rifle) info(at_rifle) squadcontent(mp2/rus/at_rifle:1 mp2/rus/motostrelk_spotter:1))
;===============================Морпехи===========================================
("squad" side(rus) t(all) name(mor) info(mor) squadcontent(mp2/rus/mor_com:1 mp2/rus/mor_mgun:1 mp2/rus/mor_mgunhelp:1 mp2/rus/mor_rpg:1 mp2/rus/mor_rpghelp:1 mp2/rus/mor_zamcom:1 mp2/rus/mor_smg2:1 mp2/rus/mor_sniper:1))
("squad" side(rus) t(all) name(mor_flame) info(mor_flame) squadcontent(mp2/rus/mor_com:1 mp2/rus/mor_mgun:1 mp2/rus/mor_mgunhelp:1 mp2/rus/mor_rpg:1 mp2/rus/mor_rpghelp:1 mp2/rus/mor_zamcom:1 mp2/rus/mor_smg2:1 mp2/rus/morspec_sniper:1 mp2/rus/flamer2:2))
("squad" side(rus) t(all) name(morspec) info(morspec) squadcontent(mp2/rus/morspec_com:1 mp2/rus/morspec_mgun:1 mp2/rus/morspec_rpg:1 mp2/rus/morspec_rpghelp:1 mp2/rus/morspec_smg:1 mp2/rus/morspec_smg2:1 mp2/rus/morspec_smg3:1 mp2/rus/morspec_sniper:1 mp2/rus/morspec_sniper1:1 mp2/rus/morspec_zamcom:1))
("squad" side(rus) t(all) name(snipers2_mor) info(snipers3) squadcontent(mp2/rus/morpeh_sniper:1 mp2/rus/morpeh_spotter:1))
("squad" side(rus) t(all) name(at_rifle_mor) info(snipers4) squadcontent(mp2/rus/mor_at_rifle:1 mp2/rus/morpeh_spotter:1))
;===============================ВДВ===========================================
("squad" side(rus) t(all) name(stormtroopers2) info(stormtroopers2) squadcontent(mp2/rus/vdv_com:1 mp2/rus/vdv_mgun:1 mp2/rus/vdv_smg:1 mp2/rus/vdv_rpg:1 mp2/rus/vdv_rpghelp:1 mp2/rus/vdv_smg2:1 mp2/rus/vdv_smg:1 mp2/rus/vdv_sniper:1 mp2/rus/vdv_zamcom:1))



;========================== usa ============================
;===============================Common=========================================== 
("squad" side(usa) t(all) name(bazookers) info(bazookers) squadcontent(mp2/usa/smg_bazooker2:1 mp2/usa/smg_help_bazooker2:1))
("squad" side(usa) t(all) name(bazookers2) info(bazookers2) squadcontent(mp2/usa/smg_jav:1 mp2/usa/smg_helpjav:1))
("squad" side(usa) t(all) name(pzrk) info(pzrk) squadcontent(mp2/usa/pzrk_new:1 mp2/usa/pzrkhelp_new:1))
("squad" side(usa) t(all) name(smg) info(smg) squadcontent(mp2/usa/smg_newcom:1 mp2/usa/smg_new:2 mp2/usa/smg_gren:2 mp2/usa/smg_mgun:2 mp2/usa/smg_bazooker:2))
;===============================Вспомогательные войска=========================================== supl
("squad" side(usa) t(all) name(tankman) info(tankman) squadcontent(mp2/usa/tankman:1))
("squad" side(usa) t(all) name(vehicle_supporter) info(vehicle_supporter) squadcontent(mp2/usa/vehicle_supporter:2))
("squad" side(usa) t(all) name(operator_bpla) info(operator_bpla) squadcontent(mp2/usa/operator_bpla:1))
("squad" side(usa) t(all) name(pilot) info(pilot) squadcontent(mp2/usa/pilot:1))
("s_squad" side(usa) t(all transfer_forbiden) name(uni_miners) info(uni_miners) squadcontent(mp2/usa/universal_miner:5)
inv(
	{item "mine antipersonnel_claymore" {count 40} {regeneration_time 990}} 
	{item "mine antitank_m21" {count 25} {regeneration_time 990}}
	)
)
("s_squad" side(usa) t(all transfer_forbiden) name(engineers) info(engineers) squadcontent(mp2/usa/engineer:5)
inv(
		{item "barbwire_kit" {count 15} {regeneration_time 495}} ; 1 items will be regenerated for 165sec
		{item "hedgehog_kit" {count 20} {regeneration_time 660}}
		{item "sandbag_kit" {count 20} {regeneration_time 440}}
		{item "dot_wood_kit" {count 3} {regeneration_time 1240}}
		{item "blindage_wood_kit" {count 1} {regeneration_time 1240}}
		{item "supp_point_kit" {count 1} {regeneration_time 1240}}
	)
)
("s_squad" side(usa) t(all transfer_forbiden) name(corpsman) info(corpsman) squadcontent(mp2/usa/corpsman:1) inv())
;===============================USAF===========================================
;===============================US AA===========================================
;===============================US artillery===========================================
("squad" side(usa) t(all) name(sappers) info(sappers) squadcontent(mp2/usa/saper:1))
("squad" side(usa) t(all) name(spotters) info(spotters) squadcontent(mp2/usa/navyseal_com_art:1 mp2/usa/navyseal_marksman_art:1 mp2/usa/navyseal_smg_art:1))
;===============================US Army===========================================
("squad" side(usa) t(all) name(usara) info(usara) squadcontent(mp2/usa/usara_com:1 mp2/usa/usara_smg:2 mp2/usa/usara_grenade:2 mp2/usa/usara_light_mgun:2 mp2/usa/usara_marksman:1 mp2/usa/usara_heavy_mgun:1))
("squad" side(usa) t(all) name(us_army_sniper) info(us_army_sniper) squadcontent(mp2/usa/us_army_sniper:1 mp2/usa/us_army_spotter:1))
("squad" side(usa) t(all) name(at_rifle) info(at_rifle) squadcontent(mp2/usa/usara_at_rifle:1 mp2/usa/usara_spotter:1))
("squad" side(usa) t(all) name(defend) info(defend) squadcontent(mp2/usa/delta_com:1 mp2/usa/delta_smg:1 mp2/usa/delta_smg2:1 mp2/usa/delta_smg3:1 mp2/usa/delta_mgun:1 mp2/usa/delta_marksman:1 mp2/usa/delta_bazooker:3))
;===============================USMC===========================================
("squad" side(usa) t(all) name(usmc) info(usmc) squadcontent(mp2/usa/usmc_com:1 mp2/usa/usmc_zamcom:5 mp2/usa/usmc_light_mgun:2 mp2/usa/usmc_smg:1 mp2/usa/usmc_marksman:1 mp2/usa/usmc_bazooker:1))
("squad" side(usa) t(all) name(usmc_sturm) info(usmc_sturm) squadcontent(mp2/usa/usmc_bazooker:2 mp2/usa/usmc_saper:2))
("squad" side(usa) t(all) name(usmc_sniper) info(usmc_sniper) squadcontent(mp2/usa/usmc_sniper:1 mp2/usa/usmc_spotter:1))
("squad" side(usa) t(all) name(usmc_heavy_sniper) info(usmc_heavy_sniper) squadcontent(mp2/usa/usmc_heavy_sniper:1 mp2/usa/usmc_spotter:1))
("squad" side(usa) t(all) name(usmcspec) info(usmcspec) squadcontent(mp2/usa/navyseal_com:1 mp2/usa/navyseal_smg:1 mp2/usa/navyseal_smg2:1 mp2/usa/navyseal_smg3:1 mp2/usa/navyseal_mgun:1 mp2/usa/navyseal_marksman:1 mp2/usa/navyseal_bazooker:3))
;===========================Цахал==============================================
("squad" side(usa) t(all) name(idf) info(idf) squadcontent(mp2/idf/idf_com:1 mp2/idf/idf_smg:1 mp2/idf/idf_hmgun:1 mp2/idf/idf_bazooker:1 mp2/idf/idf_marksman:1 mp2/idf/idf_bazooker2:1 mp2/idf/idf_smg2:1))

("squad" side(usa) t(all) name(idf_at_rifle) info(idf_at_rifle) squadcontent(mp2/idf/idf_at_rifle:1 mp2/idf/idf_spotter:1))
("squad" side(usa) t(all) name(idf_sniper) info(idf_sniper) squadcontent(mp2/idf/idf_sniper:1 mp2/idf/idf_spotter:1))

("squad" side(usa) t(all) name(idf_vdv) info(idf_vdv) squadcontent(mp2/idf/sayeret_matkal_com:1 mp2/idf/sayeret_matkal_smg:2 mp2/idf/sayeret_matkal_mgun:1 mp2/idf/sayeret_matkal_bazooker:1 mp2/idf/sayeret_matkal_bazooker2:1 mp2/idf/sayeret_matkal_marksman:1 mp2/idf/sayeret_matkal_smg2:2 mp2/idf/sayeret_matkal_heavy_mgun:1))

