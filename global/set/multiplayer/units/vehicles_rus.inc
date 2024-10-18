;===============================общие войска=========================================== 
{"mtlb" ("v_s" t(all) s(rus) sc(20) cw(0) cp(5) n(2))}
{"pzrk2_rus" ("v_s_inf" c1(mtlb) t(all) s(rus) sc(90) cw(0) cp(0) n(2) secondcrew(mp2/rus/pzrk:2 mp2/rus/pzrkhelp:2))}

{"mtlb_new" ("v_s" t(all) s(rus) sc(20) cw(0) cp(5) n(2))}
{"kord_stan" ("v_s" t(all) s(rus) sc(45) cw(10) cp(5) n(2))}
{"ags30_stan" ("v_s" t(all) s(rus) sc(120) cw(10) cp(15) n(2))}
{"2b11" ("v_s" t(all) s(rus) sc(180) cw(5) cp(20) n(2))}
{"2b11_trailer" ("v_trailer" c1(mtlb_new) c2(2b11) t(all) s(rus) sc(180) cw(5) cp(20) n(2) secondcrew(mp2/rus/vehicle_supporter:2))}

{"ptur_konkurs" ("v_s" t(all) s(rus) sc(55) cw(1) cp(5) n(2))}
{"metis_m" ("v_s" t(all) s(rus) sc(45) cw(1) cp(5) n(1))}
{"kornet_base_stan" ("v_s" t(all) s(rus) sc(140) cw(1) cp(20) n(2))}

{"shilka" ("v_t" t(all) s(rus) sc(100) cw(0) cp(15) n(4))}
{"9k35_strela-10mn" ("v_t" t(all) s(rus) sc(120) cw(0) cp(15) n(3))}

{"btr80_new" ("v_t" t(all) s(rus) sc(40) cw(20) cp(5) n(2))}
{"btr82a" ("v_t" t(all) s(rus) sc(60) cw(20) cp(15) n(2))}
{"ural375" ("v_s" t(all) s(rus) sc(10) cw(0) cp(1) n(2))}
{"ural375i" ("v_s_inf" c1(ural375) t(all) s(rus) sc(75) cw(0) cp(2) n(1) secondcrew(mp2/rus/mso_com:1 mp2/rus/mso_mgun:1 mp2/rus/mso_mgunhelp:1 mp2/rus/mso_rpg:1 mp2/rus/mso_rpghelp:1 mp2/rus/mso_smg2:2))}
{"btr80_newi" ("v_t_inf" c1(btr80_new) t(all) s(rus) sc(110) cw(0) cp(5) n(2) secondcrew(mp2/rus/mso_com:1 mp2/rus/mso_mgun:1 mp2/rus/mso_mgunhelp:1 mp2/rus/mso_rpg:1 mp2/rus/mso_rpghelp:1 mp2/rus/mso_smg2:2))}
{"btr82ai" ("v_t_inf" c1(btr82a) t(all) s(rus) sc(130) cw(0) cp(15) n(2) secondcrew(mp2/rus/mso_com:1 mp2/rus/mso_mgun:1 mp2/rus/mso_mgunhelp:1 mp2/rus/mso_rpg:1 mp2/rus/mso_rpghelp:1 mp2/rus/mso_smg2:2))}
{"brdm2" ("v_s" t(all) s(rus) sc(45) cw(10) cp(10) n(4))}

;===============================Вспомогательные войска=========================================== supl
{"ural_art" ("v_s" t(all) s(rus) sc(50) cw(0) cp(1) n(2))}
{"ural_eng" ("v_s" t(all) s(rus) sc(25) cw(0) cp(1) n(2))}
{"ural-4320_fuel" ("v_s" t(all) s(rus) sc(15) cw(0) cp(1) n(2))}

{"rus_las_designator" ("v_s" t(all) s(rus) sc(10) cw(0) cp(1) n(1))}
{"eleron_control" ("v_s" t(all) s(rus) sc(30) cw(5) cp(2) n(1))}
{"eleron_catapult" ("v_s" t(all) s(rus) sc(45) cw(5) cp(2) n(1))}
{"eleron_complex" ("v_trailer" c1(eleron_control) c2(eleron_catapult) t(all) s(rus) sc(75) cw(0) cp(5) n(1) secondcrew(mp2/rus/vehicle_supporter:1))}

{"ur_83p" ("v_s" t(all) s(rus) sc(50) cw(1) cp(5) n(2))}
{"psnr5m" ("v_s" t(all) s(rus) sc(150) cw(1) cp(35) n(2))}

;===============================ВВС===========================================
{"mi-24v_2" ("v_heli" t(all) s(rus) sc(170) cw(0) cp(20) n(2))}
{"mi28ub" ("v_heli" t(all) s(rus) sc(230) cw(0) cp(25) n(2))}
{"ka52" ("v_heli" t(all) s(rus) sc(280) cw(0) cp(30) n(2))}

{"su-25sm_support_light" ("v_p" t(all) s(rus) sc(300) cw(0) cp(25) n(1))}

{"su-34_antirad" ("v_p" t(all) s(rus) sc(200) cw(0) cp(45) n(2))}
{"su-34_medbomber_light" ("v_p" t(all) s(rus) sc(350) cw(0) cp(30) n(2))}
{"su-34_accurate_2" ("v_p" t(all) s(rus) sc(450) cw(0) cp(50) n(2))}

{"ka52_germes" ("v_heli" t(all) s(rus) sc(480) cw(0) cp(100) n(2))}

{"mi8amtsh" ("v_heli" t(all) s(rus) sc(10) cw(0) cp(2) n(2))}
{"sso" ("v_heli_inf" c1(mi8amtsh) t(all) s(rus) sc(80) cw(0) cp(2) n(2) secondcrew(mp2/rus/scout_mso_com:1 mp2/rus/scout_mso_mgun:1 mp2/rus/scout_mso_smg:2 mp2/rus/scout_mso_smg2:2 mp2/rus/scout_mso_sniper:1))}

{"shahed136_base" ("v_p" t(all) s(rus) sc(10) cw(0) cp(2) n(0))}
{"su-34_kab" ("v_p" t(all) s(rus) sc(200) cw(0) cp(50) n(1))}
{"su-35_strike" ("v_p" t(all) s(rus) sc(200) cw(0) cp(100) n(1))}
;===============================ПВО===========================================
{"su-35_aa" ("v_p" t(all) s(rus) sc(390) cw(0) cp(50) n(1))}
{"mig-29s_aa_r77" ("v_p" t(all) s(rus) sc(290) cw(0) cp(40) n(1))}

{"tor_m2" ("v_t" t(all) s(rus) sc(150) cw(0) cp(20) n(4))}
{"pantsir_s1" ("v_t" t(all) s(rus) sc(260) cw(0) cp(30) n(3))}
{"buk_m2" ("v_t" t(all) s(rus) sc(200) cw(0) cp(40) n(4))}
{"9s18_kupol" ("v_t" t(all) s(rus) sc(80) cw(0) cp(15) n(4))}

{"p-37" ("v_s" t(all) s(rus) sc(70) cw(0) cp(15) n(4))}
{"p-37_trailer" ("v_trailer" c1(mtlb_new) c2(p-37) t(all) s(rus) sc(80) cw(5) cp(18) n(2) secondcrew(mp2/rus/vehicle_supporter:4))}
{"box_weapon_rus_krasnopol" ("v_s" t(all) s(rus) sc(50) cw(0) cp(2) n(2))}
{"box_weapon_rus_smerch_cl" ("v_s" t(all) s(rus) sc(100) cw(0) cp(2) n(2))}
{"box_weapon_rus_smerch_tb" ("v_s" t(all) s(rus) sc(100) cw(0) cp(2) n(2))}
{"box_weapon_rus_tornado_s_fg" ("v_s" t(all) s(rus) sc(100) cw(0) cp(2) n(2))}

{"buk_m1" ("v_t" t(all) s(rus) sc(150) cw(0) cp(40) n(4))}
{"pantsir_s" ("v_t" t(all) s(rus) sc(150) cw(0) cp(40) n(3))}
{"su-50_aa" ("v_p" t(all) s(rus) sc(200) cw(0) cp(50) n(1))}

;===============================Артиллеристы===========================================
{"d30" ("v_s" t(all) s(rus) sc(150) cw(5) cp(20) n(2))}
{"d30_trailer" ("v_trailer" c1(mtlb_new) c2(d30) t(all) s(rus) sc(250) cw(5) cp(20) n(2) secondcrew(mp2/rus/vehicle_supporter:2))}

{"2a65_msta_b" ("v_s" t(all) s(rus) sc(200) cw(5) cp(20) n(2))}
{"msta_b_trailer" ("v_trailer" c1(mtlb_new) c2(2a65_msta_b) t(all) s(rus) sc(400) cw(5) cp(20) n(2) secondcrew(mp2/rus/vehicle_supporter:2))}
{"mstasm2" ("v_t" t(all) s(rus) sc(650) cw(0) cp(65) n(4))}
{"2s7m_malka" ("v_t" t(all) s(rus) sc(550) cw(0) cp(65) n(6))}
{"ural-4320_tornado_g" ("v_s" t(all) s(rus) sc(600) cw(0) cp(50) n(2))}
{"bm-30_tornado_s" ("v_s" t(all) s(rus) sc(850) cw(0) cp(75) n(4))}
{"iskander" ("v_t" t(all) s(rus) sc(1200) cw(0) cp(80) n(3))}
{"tos-1a_solntsepek" ("v_t" t(all) s(rus) sc(400) cw(0) cp(70) n(3))}
{"eleron3sv" ("v_s" t(all) s(rus) sc(30) cw(0) cp(2) n(0))}


{"2c3_akaciya" ("v_t" t(all) s(rus) sc(250) cw(0) cp(50) n(4))}
{"bm-30_smerch" ("v_s" t(all) s(rus) sc(400) cw(0) cp(70) n(4))}
{"koalition" ("v_t" t(all) s(rus) sc(1000) cw(0) cp(100) n(3))}
{"lancet3m_catapult" ("v_s" t(all) s(rus) sc(50) cw(0) cp(5) n(1))}
{"lancet3m_catapult_complex" ("v_trailer" c1(eleron_control) c2(lancet3m_catapult) t(all) s(rus) sc(50) cw(5) cp(5) n(1) secondcrew(mp2/rus/vehicle_supporter:1))}

;===============================Мотострелки===========================================
{"bmp2_new" ("v_t" t(all) s(rus) sc(75) cw(20) cp(20) n(3))}
{"bmp3_2022_sh1" ("v_t" t(all) s(rus) sc(200) cw(20) cp(35) n(3))}
{"bmp3_2022_dz"  ("v_t" t(all) s(rus) sc(210) cw(20) cp(35) n(3))}
{"bmp2m_new" ("v_t" t(all) s(rus) sc(150) cw(20) cp(35) n(3))}
{"bmp2_kit_new" ("v_t" t(all) s(rus) sc(95) cw(20) cp(20) n(3))}
{"bmp3_2" ("v_t" t(all) s(rus) sc(190) cw(20) cp(35) n(3))}

{"ural375i_mot" ("v_s_inf" c1(ural375) t(all) s(rus) sc(80) cw(0) cp(2) n(1) secondcrew(mp2/rus/spec_com:1 mp2/rus/spec_mgun:1 mp2/rus/spec_mgunhelp:1 mp2/rus/spec_rpg:1 mp2/rus/spec_rpghelp:1 mp2/rus/spec_zamcom:1 mp2/rus/spec_smg2:1 mp2/rus/spec_sniper:1))}
{"bmp2_newi" ("v_t_inf" c1(bmp2_new) t(all) s(rus) sc(150) cw(0) cp(15) n(3) secondcrew(mp2/rus/spec_com:1 mp2/rus/spec_mgun:1 mp2/rus/spec_mgunhelp:1 mp2/rus/spec_rpg:1 mp2/rus/spec_rpghelp:1 mp2/rus/spec_zamcom:1 mp2/rus/spec_smg2:1))}
{"bmp2_kit_newi" ("v_t_inf" c1(bmp2_kit_new) t(all) s(rus) sc(170) cw(0) cp(15) n(3) secondcrew(mp2/rus/spec_com:1 mp2/rus/spec_mgun:1 mp2/rus/spec_mgunhelp:1 mp2/rus/spec_rpg:1 mp2/rus/spec_rpghelp:1 mp2/rus/spec_zamcom:1 mp2/rus/spec_smg2:1))}
{"bmp3_2i" ("v_t_inf" c1(bmp3_2) t(all) s(rus) sc(265) cw(0) cp(15) n(3) secondcrew(mp2/rus/spec_com:1 mp2/rus/spec_mgun:1 mp2/rus/spec_mgunhelp:1 mp2/rus/spec_rpg:1 mp2/rus/spec_rpghelp:1 mp2/rus/spec_zamcom:1))}
{"bmp2m_newi" ("v_t_inf" c1(bmp2m_new) t(all) s(rus) sc(225) cw(0) cp(15) n(3) secondcrew(mp2/rus/spec_com:1 mp2/rus/spec_mgun:1 mp2/rus/spec_mgunhelp:1 mp2/rus/spec_rpg:1 mp2/rus/spec_rpghelp:1 mp2/rus/spec_zamcom:1))}
{"bmp3_2022_sh1i" ("v_t_inf" c1(bmp3_2022_sh1) t(all) s(rus) sc(275) cw(0) cp(15) n(3) secondcrew(mp2/rus/spec_com:1 mp2/rus/spec_mgun:1 mp2/rus/spec_mgunhelp:1 mp2/rus/spec_rpg:1 mp2/rus/spec_rpghelp:1 mp2/rus/spec_zamcom:1))}
{"bmp3_2022_dzi" ("v_t_inf" c1(bmp3_2022_dz) t(all) s(rus) sc(285) cw(0) cp(15) n(3) secondcrew(mp2/rus/spec_com:1 mp2/rus/spec_mgun:1 mp2/rus/spec_mgunhelp:1 mp2/rus/spec_rpg:1 mp2/rus/spec_rpghelp:1 mp2/rus/spec_zamcom:1))}

{"vasilek" ("v_s" t(all) s(rus) sc(180) cw(5) cp(20) n(2))}
{"vasilek_trailer" ("v_trailer" c1(mtlb_new) c2(vasilek) t(all) s(rus) sc(180) cw(5) cp(20) n(2) secondcrew(mp2/rus/vehicle_supporter:2))}
{"9p149_shturm-s" ("v_t" t(all) s(rus) sc(170) cw(0) cp(20) n(2))}

{"t72b" ("v_t" t(all) s(rus) sc(250) cw(0) cp(50) n(3))}
{"t72b3" ("v_t" t(all) s(rus) sc(320) cw(0) cp(50) n(3))}
{"t72b3_2017" ("v_t" t(all) s(rus) sc(360) cw(0) cp(50) n(3))}

{"t-90a" ("v_t" t(all) s(rus) sc(300) cw(0) cp(65) n(3))}
{"t-14" ("v_t" t(all) s(rus) sc(500) cw(0) cp(65) n(3))}
{"t-15_au220" ("v_t" t(all) s(rus) sc(350) cw(0) cp(65) n(3))}
{"bmpt" ("v_t" t(all) s(rus) sc(350) cw(0) cp(60) n(5))}

;===============================Морпехи===========================================

{"ural375i_mor" ("v_s_inf" c1(ural375) t(all) s(rus) sc(80) cw(0) cp(2) n(1) secondcrew(mp2/rus/mor_com:1 mp2/rus/mor_mgun:1 mp2/rus/mor_mgunhelp:1 mp2/rus/mor_rpg:1 mp2/rus/mor_rpghelp:1 mp2/rus/mor_zamcom:1 mp2/rus/mor_smg2:1 mp2/rus/morspec_sniper:1))}
{"bmp2_kit_newi_mor" ("v_t_inf" c1(bmp2_kit_new) t(all) s(rus) sc(150) cw(0) cp(15) n(3) secondcrew(mp2/rus/mor_com:1 mp2/rus/mor_mgun:1 mp2/rus/mor_mgunhelp:1 mp2/rus/mor_rpg:1 mp2/rus/mor_rpghelp:1 mp2/rus/mor_zamcom:1 mp2/rus/mor_smg2:1 ))}
{"bmp3_2i_mor" ("v_t_inf" c1(bmp3_2) t(all) s(rus) sc(245) cw(0) cp(15) n(3) secondcrew(mp2/rus/mor_com:1 mp2/rus/mor_mgun:1 mp2/rus/mor_mgunhelp:1 mp2/rus/mor_rpg:1 mp2/rus/mor_rpghelp:1 ))}

{"gaz_tigr" ("v_s" t(all) s(rus) sc(130) cw(0) cp(20) n(3))}
{"brdm2_atgm" ("v_t" t(all) s(rus) sc(110) cw(0) cp(20) n(2))}
{"kornet-d" ("v_s" t(all) s(rus) sc(350) cw(0) cp(40) n(2))}

{"t80bv_2" ("v_t" t(all) s(rus) sc(250) cw(0) cp(50) n(3))}
{"t80bvm" ("v_t" t(all) s(rus) sc(360) cw(0) cp(65) n(3))}
{"2b14_podnos" ("v_s" t(all) s(rus) sc(100) cw(5) cp(25) n(2))}

{"t72b3_2017_2" ("v_t" t(all) s(rus) sc(300) cw(0) cp(65) n(3))}
{"ka52k" ("v_heli" t(all) s(rus) sc(300) cw(0) cp(100) n(2))}

;===============================ВДВ===========================================
{"btr-d" ("v_custom" t(all) s(rus) sc(10) cw(30) cp(15) crew(mp2/rus/vdv_tankman:2))}
{"bmd2" ("v_custom" t(all) s(rus) sc(70) cw(30) cp(25) crew(mp2/rus/vdv_tankman:2))}
{"bmd4m_sadovnitsa" ("v_custom" t(all) s(rus) sc(215) cw(30) cp(30) crew(mp2/rus/vdv_tankman:3))}

{"btr-di" ("v_vdv_inf" c1(btr-d) t(all) s(rus) sc(85) cw(0) cp(30) n(2) secondcrew(mp2/rus/vdv_com:1 mp2/rus/vdv_mgun:1 mp2/rus/mor_mgunhelp:1 mp2/rus/vdv_smg:1 mp2/rus/vdv_rpg2:1 mp2/rus/vdv_rpghelp2:1 mp2/rus/vdv_smg2:1 mp2/rus/vdv_smg:1 mp2/rus/vdv_zamcom:1))}
{"bmd2i" ("v_vdv_inf" c1(bmd2) t(all) s(rus) sc(125) cw(0) cp(30) n(2) secondcrew(mp2/rus/vdv_com:1 mp2/rus/vdv_mgun:1 mp2/rus/mor_mgunhelp:1 mp2/rus/vdv_rpg:1 mp2/rus/vdv_sniper:1 ))}
{"bmd4m_sadovnitsai" ("v_vdv_inf" c1(bmd4m_sadovnitsa) t(all) s(rus) sc(275) cw(0) cp(30) n(3) secondcrew(mp2/rus/vdv_com:1 mp2/rus/vdv_mgun:1 mp2/rus/vdv_rpg:1 mp2/rus/vdv_sniper:1 mp2/rus/vdv_smg2:1))}

{"btr-rd" ("v_custom" t(all) s(rus) sc(180) cw(30) cp(15) crew(mp2/rus/vdv_tankman:2))}
{"2c9" ("v_custom" t(all) s(rus) sc(320) cw(30) cp(25) crew(mp2/rus/vdv_tankman:4))}
{"sprutsd" ("v_custom" t(all) s(rus) sc(210) cw(30) cp(20) crew(mp2/rus/vdv_tankman:3))}

{"mi8amtsh1_mgun" ("v_heli" t(all) s(rus) sc(10) cw(0) cp(2) n(2))}
{"mi8amtsh1_mguni" ("v_heli_inf" c1(mi8amtsh1_mgun) t(all) s(rus) sc(130) cw(0) cp(5) n(2) secondcrew(mp2/rus/vdv_com:1 mp2/rus/vdv_mgun:1 mp2/rus/vdv_smg:1 mp2/rus/vdv_rpg:1 mp2/rus/vdv_rpghelp:1 mp2/rus/vdv_smg2:1 mp2/rus/vdv_smg:1 mp2/rus/vdv_sniper:1 mp2/rus/vdv_zamcom:1))}

{"mi8amtsh1_mgnar" ("v_heli" t(all) s(rus) sc(10) cw(0) cp(2) n(2))}
{"mi8amtsh1_mgnari" ("v_heli_inf" c1(mi8amtsh1_mgnar) t(all) s(rus) sc(100) cw(0) cp(5) n(2) secondcrew(mp2/rus/vdv_com:1 mp2/rus/vdv_mgun:1 mp2/rus/vdv_smg:1 mp2/rus/vdv_rpg:1 mp2/rus/vdv_rpghelp:1 mp2/rus/vdv_smg2:1 mp2/rus/vdv_smg:1 mp2/rus/vdv_sniper:1 mp2/rus/vdv_zamcom:1))}
{"kornet_stan" ("v_s" t(all) s(rus) sc(100) cw(1) cp(25) n(2))}
{"mi-24vm" ("v_heli" t(all) s(rus) sc(200) cw(0) cp(30) n(2))}
