;decoyprob - every decoy, several times
;spawn_proj_5, 7, 9, 15 - target illumination time
;country(rus) or usa - marker type

;type(antiship)
;type(radpassive) - passive targeting
;type(laser)
;type(active) - active radiolocator
;type(ir) - IR seeker
;type(other) - 
;do not include antirad missiles here

;weapon_tag(reflex_target) - just indicator
;decoytype(optic), chaff, flare - optic (shtora), IR (flares), radio (ecm and chaff)
;decoyprob(0.04) - vulnerability to decoys
;min_alt(14) - minimal altitude where guidanse still work

;gun-launched missiles
{if stuff "bullet125_RUS rok"				
	("spawn_proj_5" country(rus) type(laser) weapon_tag(reflex_target) decoytype(optic) decoyprob(0.04) min_alt(-100))			
	else stuff "bullet100a_RUS rok ammo"				
	("spawn_proj_7" country(rus) type(laser) weapon_tag(9m117_target) decoytype(optic) decoyprob(0.04) min_alt(-100))	
	else stuff "bullet100a_RUS_h rok ammo"				
	("spawn_proj_7" country(rus) type(laser) weapon_tag(9m117m_target) decoytype(optic) decoyprob(0.04) min_alt(-100))	
	else stuff "bullet115_RUS rok ammo"				
	("spawn_proj_7" country(rus) type(laser) weapon_tag(9m117_115_target) decoytype(optic) decoyprob(0.04) min_alt(-100))			
	else stuff "bullet105_cn rok ammo"				
	("spawn_proj_7" country(rus) type(laser) weapon_tag(9m117cn_target) decoytype(optic) decoyprob(0.04) min_alt(-100))	
	else stuff "bullet100_cn_rapira rok ammo"				
	("spawn_proj_7" country(rus) type(laser) weapon_tag(9m117cn100_target) decoytype(optic) decoyprob(0.04) min_alt(-100))	
	else stuff "bullet125_h_rus rok ammo"				
	("spawn_proj_7" country(rus) type(laser) weapon_tag(9m119m_target) decoytype(optic) decoyprob(0.04) min_alt(-100))	
	else stuff "bullet125_m_rus rok ammo"				
	("spawn_proj_7" country(rus) type(laser) weapon_tag(9m119m1_target) decoytype(optic) decoyprob(0.04) min_alt(-100))	
	else stuff "lahat rok ammo"				
	("spawn_proj_7" country(usa) type(laser) weapon_tag(lahat_target) decoytype(optic) decoyprob(0.2) min_alt(-100))
	else stuff "tur_kobra ammo"				
	("spawn_proj_7" country(rus) type(laser) weapon_tag(tur_kobra_target) decoytype(optic) decoyprob(0.04) min_alt(-100))			
	else stuff "tur_kombat ammo"				
	("spawn_proj_7" country(rus) type(laser) weapon_tag(tur_kombat_target) decoytype(optic) decoyprob(0.04) min_alt(-100))
;ATGM RU
	else stuff "9k14m ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(9k14m_target) decoytype(optic) decoyprob(0.04) min_alt(-100))
	else stuff "hj73c hj73 ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(hj73c_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "fagot_concurs 9m111 ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(9k111_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "fagot_concurs 9m111m ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(9k111m_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "fagot_concurs 9m113 ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(9k113_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "fagot_concurs 9m113m ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(9k113m_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "fagot_concurs 9m113m1 ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(9k113m1_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "9m114m cm ammo"				
	("spawn_proj_5" country(rus) type(other) weapon_tag(9m114m_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "9m114m fg ammo"				
	("spawn_proj_5" country(rus) type(other) weapon_tag(9m114f_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "9k115-2 cm_e ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(9k115-1_cm_target) decoytype(optic) decoyprob(0.3) min_alt(-100))		
	else stuff "9k115-2 cm ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(9k115-2_cm_target) decoytype(optic) decoyprob(0.3) min_alt(-100))		
	else stuff "9m120 cm ammo"			
	("spawn_proj_5" country(rus) type(other) weapon_tag(9m120m_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "9m120 fg ammo"			
	("spawn_proj_5" country(rus) type(other) weapon_tag(9m120f_target) decoytype(optic) decoyprob(0.05) min_alt(-100))	
	else stuff "9m133 cm ammo"			
	("spawn_proj_9" country(rus) type(laser) weapon_tag(9m133_1_cm_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "9m133 cm_e ammo"			
	("spawn_proj_9" country(rus) type(laser) weapon_tag(9m133_cm_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "9m133 fg ammo"			
	("spawn_proj_9" country(rus) type(laser) weapon_tag(9m133_fg_target) decoytype(optic) decoyprob(0.05) min_alt(-100))	
	else stuff "9m133 tb ammo"			
	("spawn_proj_9" country(rus) type(laser) weapon_tag(9m133_tb_target) decoytype(optic) decoyprob(0.05) min_alt(-100))	
	else stuff "vixr_ammo"			
	("spawn_proj_5" country(rus) type(laser) weapon_tag(vixr_target) decoytype(optic) decoyprob(0.04) min_alt(-100))	 
	else stuff "germes"		
	("spawn_proj_9" country(rus) type(ir) weapon_tag(germes_target) decoytype(flare) decoyprob(0.1) min_alt(-100))	 
	else stuff "shershen cm ammo"			
	("spawn_proj_9" country(rus) type(laser) weapon_tag(shershen_ammo_cm_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "shershen fg ammo"			
	("spawn_proj_9" country(rus) type(laser) weapon_tag(shershen_ammo_fg_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "lancet3m_ammo fg ammo"				
	("spawn_proj_5" country(rus) type(other) weapon_tag(lancet3m_fg_target) decoytype(optic) decoyprob(0) min_alt(-100))
	else stuff "lancet3m_ammo cm ammo"				
	("spawn_proj_5" country(rus) type(other) weapon_tag(lancet3m_cm_target) decoytype(optic) decoyprob(0) min_alt(-100))
;ATGM NATO
	else stuff "hellfire ammo"			
	("spawn_proj_7" country(usa) type(active) weapon_tag(hellfire_target) decoytype(chaff) decoyprob(0.3) min_alt(-100))	
	else stuff "agm-114 k ammo"	                              			
	("spawn_proj_7" country(usa) type(laser) weapon_tag(agm-114k_target) decoytype(optic) decoyprob(0.07) min_alt(-100))	
	else stuff "agm-114 k2 ammo"			
	("spawn_proj_7" country(usa) type(laser) weapon_tag(agm-114k2_target) decoytype(optic) decoyprob(0.07) min_alt(-100))
	else stuff "agm-114 l ammo"			
	("spawn_proj_7" country(usa) type(active) weapon_tag(agm-114l_target) decoytype(chaff) decoyprob(0.3) min_alt(-100))	
	else stuff "agm-114 n ammo"			
	("spawn_proj_7" country(usa) type(laser) weapon_tag(agm-114n_target) decoytype(optic) decoyprob(0.15) min_alt(-100))	
	else stuff "agm-114 r ammo"			
	("spawn_proj_7" country(usa) type(laser) weapon_tag(agm-114r_target) decoytype(optic) decoyprob(0.3) min_alt(-100))	
	else stuff "brimstone ammo"	                    	
	("spawn_proj_9" country(usa) type(active) weapon_tag(brimstone_target) decoytype(chaff) decoyprob(0.1) min_alt(-100))	
	else stuff "tow_rock ammo"				
	("spawn_proj_7" country(usa) type(other) weapon_tag(tow_target) decoytype(optic) decoyprob(0.3) min_alt(-100))	
	else stuff "tow2b ammo"	                                                                            
	("spawn_proj_7" country(usa) type(other) weapon_tag(tow2b_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "tow2d ammo"				
	("spawn_proj_7" country(usa) type(other) weapon_tag(tow2d_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "tow2e ammo"			
	("spawn_proj_7" country(usa) type(other) weapon_tag(tow2e_target) decoytype(optic) decoyprob(0.05) min_alt(-100))	
	else stuff "tow2_fg ammo"			
	("spawn_proj_7" country(usa) type(other) weapon_tag(tow2_fg_target) decoytype(optic) decoyprob(0.05) min_alt(-100))	
	else stuff "agm-65d ammo"		
	("spawn_proj_7" country(usa) type(ir) weapon_tag(agm-65D_target) decoytype(optic) decoyprob(0.15) min_alt(-100))	
	else stuff "agm-65g ammo"			
	("spawn_proj_7" country(usa) type(laser) weapon_tag(agm-65G_target) decoytype(optic) decoyprob(0.05) min_alt(-100))	
	else stuff "adats ammo"				
	("spawn_proj_7" country(usa) type(laser) weapon_tag(adats_target) decoytype(chaff) decoyprob(0.04) min_alt(-100))	
	else stuff "eryx_rock ammo"			
	("spawn_proj_7" country(usa) type(other) weapon_tag(eryx_rock_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "m47dragon_rock ammo"			
	("spawn_proj_7" country(usa) type(other) weapon_tag(m47dragon_rock_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "jav_rock ammo"			
	("spawn_proj_9" country(usa) type(ir) weapon_tag(jav_rock_target) decoytype(flare) decoyprob(0.5) min_alt(-100))
    else stuff "javf_rock ammo"			
	("spawn_proj_9" country(usa) type(ir) weapon_tag(jav_rock_target) decoytype(flare) decoyprob(0.5) min_alt(-100))	
;	else stuff "sraw_rock ammo"			
;	("spawn_proj_5" country(usa) type(other) weapon_tag(sraw_rock_target) decoytype(optic) decoyprob(0) min_alt(-100))
	else stuff "milan_rock ammo"
	("spawn_proj_7" country(usa) type(other) weapon_tag(milan_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "milan-er ammo"
	("spawn_proj_7" country(usa) type(other) weapon_tag(milan_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "hot_rock ammo"				
	("spawn_proj_7" country(usa) type(other) weapon_tag(hot_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "spike-sr ammo"				
	("spawn_proj_7" country(usa) type(ir) weapon_tag(spike-sr_target) decoytype(flare) decoyprob(0.3) min_alt(-100))
	else stuff "spike-lr ammo"				
	("spawn_proj_9" country(usa) type(other) weapon_tag(spike-lr_target) decoytype(optic) decoyprob(0) min_alt(-100))
	else stuff "spike-er ammo"			
	("spawn_proj_15" country(usa) type(other) weapon_tag(spike-er_target) decoytype(optic) decoyprob(0) min_alt(-100))
	else stuff "spike-er2 ammo"			
	("spawn_proj_15" country(usa) type(other) weapon_tag(spike-er2_target) decoytype(optic) decoyprob(0) min_alt(-100))
	else stuff "spike_nlos cm ammo"			
	("spawn_proj_15" country(usa) type(other) weapon_tag(spike_nlos_target) decoytype(optic) decoyprob(0) min_alt(-100))
	else stuff "spike_nlos fg ammo"			
	("spawn_proj_15" country(usa) type(other) weapon_tag(spike_nlos_fg_target) decoytype(optic) decoyprob(0) min_alt(-100))
	else stuff "mmp_missile ammo"			
	("spawn_proj_15" country(usa) type(other) weapon_tag(mmp_missile_target) decoytype(optic) decoyprob(0) min_alt(-100))
	else stuff "switchblade300_ammo ammo"				
	("spawn_proj_5" country(usa) type(other) weapon_tag(switchblade300_ammo_target) decoytype(optic) decoyprob(0) min_alt(-100))
	else stuff "trigat ammo"	                              			
	("spawn_proj_7" country(usa) type(ir) weapon_tag(trigat_target) decoytype(flare) decoyprob(0.10) min_alt(-100))	
	else stuff "bullet152_usa rok ammo"	
	("spawn_proj_7" country(usa) type(other) weapon_tag(Shillelagh_target) decoytype(optic) decoyprob(0.04) min_alt(-100))
;ATGM CN
	else stuff "red_arrow12_rock ammo"			
	("spawn_proj_9" country(rus) type(ir) weapon_tag(hj12e_target) decoytype(flare) decoyprob(0.5) min_alt(-100))	
	else stuff "Ten_Lei_ammo cm ammo"			
	("spawn_proj_9" country(rus) type(other) weapon_tag(Ten_Lei_ammo_target) decoytype(flare) decoyprob(0.5) min_alt(-100))	
	else stuff "hj8e ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(hj8e_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "hj8h ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(hj8h_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "hj8f ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(hj8f_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "hj9_missile ammo"				
	("spawn_proj_7" country(rus) type(other) weapon_tag(hj9_missile_target) decoytype(optic) decoyprob(0.3) min_alt(-100))
	else stuff "hj-10 hj-10b ammo"				
	("spawn_proj_15" country(rus) type(other) weapon_tag(hj-10b_target) decoytype(optic) decoyprob(0) min_alt(-100))
	else stuff "akd-10 ammo"	                              			
	("spawn_proj_7" country(rus) type(laser) weapon_tag(akd-10_target) decoytype(optic) decoyprob(0.07) min_alt(-100))	
	else stuff "ag300m ammo"				
	("spawn_proj_7" country(rus) type(laser) weapon_tag(ag300m_ammo_target) decoytype(optic) decoyprob(0.07) min_alt(-100))
	else stuff "shahed136_base_ammo ammo"				
	("spawn_proj_5" country(rus) type(other) weapon_tag(shahed136_ammo_target) decoytype(optic) decoyprob(0) min_alt(-100))

;air-to-ground
	else stuff "x_25ml_su25_ammo ammo"	
	("spawn_proj_9" country(rus) type(laser) weapon_tag(x_25ml_su25_ammo_target) decoytype(optic) decoyprob(0.15) min_alt(-100))
	else stuff "jsm ammo"			
	("spawn_proj_9" country(usa) type(antiship) weapon_tag(jsm_target) decoytype(chaff) decoyprob(0.07) min_alt(-100))
	else stuff "slam_er ammo"			
	("spawn_proj_9" country(usa) type(antiship) weapon_tag(slam_er_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "agm-130 ammo"			
	("spawn_proj_15" country(usa) type(other) weapon_tag(agm-130_target) decoytype(optic) decoyprob(0.05) min_alt(-100))
	else stuff "sdb2 ammo"			
	("spawn_proj_15" country(usa) type(active) weapon_tag(sdb_target) decoytype(chaff) decoyprob(0.15) min_alt(-100))
	else stuff "taurus ammo"			
	("spawn_proj_15" country(usa) type(other) weapon_tag(taurus_target) decoytype(optic) decoyprob(0.07) min_alt(-100))
;	else stuff "agm-154 ammo"		
;	("spawn_proj_15" country(usa) type(other) weapon_tag(agm-154_target) decoytype(chaff) decoyprob(0.01) min_alt(-100))
	else stuff "3m14 ammo"		
	("spawn_proj_15" country(rus) type(other) weapon_tag(3m14_target) decoytype(chaff) decoyprob(0.01) min_alt(-100))
	else stuff "x-38mte ammo"		
	("spawn_proj_7" country(rus) type(ir) weapon_tag(x-38mte_target) decoytype(optic) decoyprob(0.15) min_alt(-100))
;manPADs
	else stuff "igla_S ammo"		
	("spawn_proj_5" country(rus) type(ir) weapon_tag(igla_S_target) decoytype(flare) decoyprob(0.04) min_alt(4))
	else stuff "fim-92a_ammo ammo"	
	("spawn_proj_5" country(usa) type(ir) weapon_tag(fim-92a_target) decoytype(flare) decoyprob(0.04) min_alt(5))
	else stuff "fn6a_ammo ammo"	
	("spawn_proj_5" country(rus) type(ir) weapon_tag(fn6a_target) decoytype(flare) decoyprob(0.15) min_alt(8))
	else stuff "mistral_missile ammo"	
	("spawn_proj_5" country(usa) type(ir) weapon_tag(mistral_missile_target) decoytype(flare) decoyprob(0.04) min_alt(-100))
	else stuff "starstreak_ammo ammo"	
	("spawn_proj_5" country(usa) type(laser) weapon_tag(starstreak_ammo_target) decoytype(optic) decoyprob(0.07) min_alt(-100))
;SAMs
	else stuff "9m31 ammo"			
	("spawn_proj_5" country(rus) type(ir) weapon_tag(9k31_target) decoytype(flare) decoyprob(0.23) min_alt(14))
	else stuff "strela10 9m37 ammo"			
	("spawn_proj_5" country(rus) type(ir) weapon_tag(9k37_target) decoytype(flare) decoyprob(0.20) min_alt(14))
	else stuff "strela10 9m333 ammo"			
	("spawn_proj_5" country(rus) type(ir) weapon_tag(9k333_target) decoytype(flare) decoyprob(0.15) min_alt(14))
	else stuff "9m311 ammo"			
	("spawn_proj_5" country(rus) type(active) weapon_tag(9m311_target) decoytype(chaff) decoyprob(0.13) min_alt(-100))
	else stuff "pantsir 57e6e ammo"			
	("spawn_proj_9" country(rus) type(active) weapon_tag(pantsir_57e6e_target) decoytype(chaff) decoyprob(0.03) min_alt(-100))
	else stuff "aim7m ammo"			
	("spawn_proj_1" country(usa) type(active) weapon_tag(aim7m_target) decoytype(chaff) decoyprob(0.22) min_alt(5))
	else stuff "aim7m_air ammo"			
	("spawn_proj_9" country(usa) type(active) weapon_tag(aim7m_target) decoytype(chaff) decoyprob(0.22) min_alt(15))
	else stuff "9m38 ammo"			
	("spawn_proj_1" country(rus) type(active) weapon_tag(9m38_target) decoytype(chaff) decoyprob(0.21) min_alt(-100))
	else stuff "9m317 ammo"			
	("spawn_proj_1" country(rus) type(active) weapon_tag(9m317_target) decoytype(chaff) decoyprob(0.15) min_alt(-100))
	else stuff "9m33 ammo"			
	("spawn_proj_1" country(rus) type(active) weapon_tag(9m33_target) decoytype(chaff) decoyprob(0.21) min_alt(14))
	else stuff "patriot ammo"		
	("spawn_proj_5" country(usa) type(active) weapon_tag(patriot_target) decoytype(chaff) decoyprob(0.14) min_alt(-100))
	else stuff "xmim-115avt1 ammo"	
	("spawn_proj_7" country(usa) type(active) weapon_tag(xmim-115avt1_target) decoytype(chaff) decoyprob(0.05) min_alt(8))
	else stuff "rim116 ammo"	
	("spawn_proj_7" country(usa) type(ir) weapon_tag(rim116_target) decoytype(flare) decoyprob(0.03) min_alt(4))
	else stuff "hq7b ammo"	
	("spawn_proj_7" country(rus) type(active) weapon_tag(hq7b_target) decoytype(chaff) decoyprob(0.08) min_alt(8))
	else stuff "9m330 ammo"	
	("spawn_proj_7" country(rus) type(active) weapon_tag(9m330_target) decoytype(chaff) decoyprob(0.03) min_alt(6))
	else stuff "9m338 ammo"	
	("spawn_proj_7" country(rus) type(active) weapon_tag(9m338_target) decoytype(chaff) decoyprob(0.03) min_alt(6))
;AA missiles
	else stuff "aim-9l_ammo ammo"	
	("spawn_proj_7" country(usa) type(ir) weapon_tag(aim-9l_target) decoytype(flare) decoyprob(0.10) min_alt(4))
	else stuff "r-3c ammo"			
	("spawn_proj_5" country(rus) type(ir) weapon_tag(r-3c_target) decoytype(flare) decoyprob(0.2) min_alt(-100))
	else stuff "r60_su25 ammo"		
	("spawn_proj_5" country(rus) type(ir) weapon_tag(r60_su25_target) decoytype(flare) decoyprob(0.16) min_alt(4))
	else stuff "aim-120c7 ammo"		
	("spawn_proj_7" country(usa) type(active) weapon_tag(aim-120c7_target) decoytype(chaff) decoyprob(0.07) min_alt(10))
	else stuff "rvv-ae ammo"		
	("spawn_proj_7" country(rus) type(active) weapon_tag(rvv-ae_target) decoytype(chaff) decoyprob(0.07) min_alt(10))
	else stuff "rvv-sd ammo"		
	("spawn_proj_7" country(rus) type(active) weapon_tag(rvv-sd_target) decoytype(chaff) decoyprob(0.07) min_alt(10))
	else stuff "r_27er ammo"		
	("spawn_proj_7" country(rus) type(active) weapon_tag(rvv_27er_target) decoytype(chaff) decoyprob(0.16) min_alt(10))			
	else stuff "rvv-md ammo"			
	("spawn_proj_7" country(rus) type(ir) weapon_tag(rvv-md_target) decoytype(flare) decoyprob(0.10) min_alt(10))	
	else stuff "r-73 ammo"				
	("spawn_proj_7" country(rus) type(ir) weapon_tag(r-73_target) decoytype(flare) decoyprob(0.10) min_alt(4))	       		
	else stuff "pl5e2 ammo"	
	("spawn_proj_7" country(rus) type(ir) weapon_tag(pl5e2_target) decoytype(flare) decoyprob(0.10) min_alt(4))
	else stuff "pl8b ammo"	
	("spawn_proj_7" country(rus) type(ir) weapon_tag(pl8b_target) decoytype(flare) decoyprob(0.10) min_alt(4))
	else stuff "pl12 ammo"	
	("spawn_proj_7" country(rus) type(active) weapon_tag(pl12_target) decoytype(chaff) decoyprob(0.07) min_alt(10))
;other
	else stuff "targeting_radar_usa ammo"		
	{if not tagged "low_altitude" ("spawn_proj_passive" country(usa) type(radpassive) weapon_tag(targeting_radar_target) decoytype(chaff) decoyprob(0.04) min_alt(10))}	
	else stuff "targeting_radar_rus ammo"			
	{if not tagged "low_altitude" ("spawn_proj_passive" country(rus) type(radpassive) weapon_tag(targeting_radar_target) decoytype(chaff) decoyprob(0.04) min_alt(10))}
	else stuff "usa_laser ammo"
	("spawn_proj_passive" country(usa) type(laser) weapon_tag(targeting_laser_target) decoytype(optic) decoyprob(0.04) min_alt(-100))	
	else stuff "rus_laser ammo"
	("spawn_proj_passive" country(rus) type(laser) weapon_tag(targeting_laser_target) decoytype(optic) decoyprob(0.04) min_alt(-100))
	else stuff "rus_laser_spot ammo"
	("spawn_proj_5" country(rus) type(laser_spot) weapon_tag(targeting_laser_target) decoytype(optic) decoyprob(0.00) min_alt(-100))
	else stuff "usa_laser_spot ammo"
	("spawn_proj_5" country(usa) type(laser_spot) weapon_tag(targeting_laser_target) decoytype(optic) decoyprob(0.00) min_alt(-100))
;	else stuff "persmarker" 	{with_effector {call "set_decal"} {with_effector}}
}