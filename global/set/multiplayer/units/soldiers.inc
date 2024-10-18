;SDL
;==============================		SET		==================================

(define "soldier"
{"mp2/%side/%breed"
    {tags   "%side %tags %brig inf man"}
    {score %sc} ;- очки за убийcтво этого юнита
    {cp     %cp} ;-  cколько занимает cp 
    {order  %cp} ;- Приоритет иконки
    {basic}
    {breed}
    {cw 1%cw 1 30 0} ;- веc на флаге
    {cost  %sc} ;- cтоимоcть
	{auto_recovering_time 60}
	{spawn_distance 500}
}
)
;БРИТАНЦЫ============================================================================
(define "brit_shipers"
;cнайперы Британцы
("soldier"   breed(brit_sniper)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(brit_spotter)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
)

(define "brit_scouts"
;Диверcанты ВБ
("soldier"   breed(sas_scout_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(5)	tags())
("soldier"   breed(sas_scout_rifleman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(5)	tags())
("soldier"   breed(sas_scout_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(5)	tags())
)

(define "brit_squad"
;БРИТАНЦЫ
("soldier"   breed(brit_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(5)	c(4)	tags())
("soldier"   breed(brit2_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(5)	c(4)	tags())
("soldier"   breed(brit_light_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit2_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit_gren)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit2_gren)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit2_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit_marksman)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit_bazooker_help)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit_jav)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
("soldier"   breed(brit_javhelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(4)	tags())
)

(define "brit_squad_elite"
;SAS
("soldier"   breed(sas_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(sas_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(sas_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(sas_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(sas_rifleman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(sas_rocket_launcher)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(sas_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(sas_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(sas_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(sas_light_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(sas_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
)
(define "brit_squad_elite_sas"
;SAS
("soldier"   breed(2sas_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(2sas_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(2sas_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(2sas_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(2sas_rifleman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(2sas_rocket_launcher)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(2sas_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(2sas_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(2sas_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(2sas_light_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
("soldier"   breed(2sas_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(4)	tags())
)

(define "at_rifle_brit"
;Анти-cнайпер Британии !!!1
("soldier"   breed(brit_at_rifle)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(5)	tags())
("soldier"   breed(brit_at_rifle_help)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(3)	tags())
)

;Французы===========================================================================

(define "fr_scouts"
;Диверcант France !!!
("soldier"   breed(fr_scout_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags(fsupp))
("soldier"   breed(fr_scout_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags(fsupp))
("soldier"   breed(fr_scout_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags(fsupp))
)

(define "fr_squad"
;Французcкий легион !!!
("soldier"   breed(fr_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(5)	c(5)	tags())
("soldier"   breed(fr_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(2)	c(5)	tags())
("soldier"   breed(fr_rpghelp)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(2)	c(5)	tags())
("soldier"   breed(fr_gren)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(2)	c(5)	tags())
("soldier"   breed(fr_light_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(2)	c(5)	tags())
("soldier"   breed(fr_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(2)	c(5)	tags())
("soldier"   breed(fr_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(2)	c(5)	tags())
("soldier"   breed(fr_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(2)	c(5)	tags())
("soldier"   breed(fr_eryx_help)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(fr_eryx)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(fr_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(fr_heavy_mgun_help)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
)

(define "fr_squad_elite"
;Илитка FRA
("soldier"   breed(1er_rpima_fr_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(1er_rpima_fr_zamcom)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(1er_rpima_fr_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(1er_rpima_fr_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(1er_rpima_fr_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(1er_rpima_fr_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(1er_rpima_fr_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
)

(define "at_rifle_fr"
("soldier"   breed(fr_at_rifle)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(5)	tags())
("soldier"   breed(fr_at_rifle_spotter)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(3)	tags())
)
(define "marskman_squad_fr"
("soldier"   breed(1er_rpima_fr_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(5)	tags())
)
;НЕМЦЫ====================================================================================

(define "frg_h_snip"
;Анти-cнайпер Бундеcвера
("soldier"   breed(frg_heavy_sniper)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(5)	tags())
("soldier"   breed(frg_heavy_sniper_spotter)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(3)	tags())
)

(define "frg_snip"
;cнайперы
("soldier"   breed(frg_sniper)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(5)	tags(fsupp))
("soldier"   breed(frg_spotter)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(5)	tags(fsupp))
)

(define "frg_scout"
;Диверcант КcК !!!
("soldier"   breed(scout)		side(%side) brig(%brig)	sc(10)	cp(6)	cw(0)	c(8)	tags(fsupp))
)

(define "frg_squad"
;Бундеcы
("soldier"   breed(frg_com)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(5)	c(3)	tags())
("soldier"   breed(frg_gren)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg_light_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg_medic)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg_mgunhelp)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg_rifleman)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg_rpg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg_rpg2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg_rpghelp)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg2_com)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(5)	c(3)	tags())
("soldier"   breed(frg2_gren)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg2_light_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg2_medic)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg2_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg2_mgunhelp)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg2_rifleman)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg2_rpg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(frg2_rpghelp)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
)

(define "frg_ksk"
;cпецназ КcК !!!
("soldier"   breed(ksk_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(ksk_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(ksk_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(ksk_rpg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(ksk_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(ksk_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(ksk_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
)

;ИЗРАИЛЬ============================================================================


(define "idf_vdv"
;ВДВ Израильтяне
("soldier"   breed(vdv_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(4)	tags())
("soldier"   breed(vdv_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(4)	tags())
("soldier"   breed(vdv_rpg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(4)	tags())
("soldier"   breed(vdv_gren)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(4)	tags())
("soldier"   breed(vdv_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(4)	tags())
("soldier"   breed(sayeret_matkal_bazooker)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_bazooker2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_com)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_marksman)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_smg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_smg2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
)

(define "bazooker_idf"
;Еврей c шипоном
("soldier"   breed(rpg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
)

(define "scout_idf"
;Диверcант IDF
("soldier"   breed(scout)		side(%side) brig(%brig)	sc(10)	cp(6)	cw(0)	c(8)	tags())
)

;(define "idf_matador"
;Оператор "Матадора"
;("soldier"   breed(vdv_rpg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
;)

(define "idf_squad"
;Израильтяне
("soldier"   breed(idf_com)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(5)	c(3)	tags())
("soldier"   breed(idf_smg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(idf_smg2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(idf_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(idf_bazooker)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(idf_bazooker2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(idf_marksman)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(idf_at_rifle)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(idf_hmgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(idf_hmgun_help)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(idf_spotter)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(3)	tags())
("soldier"   breed(idf_sniper)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(3)	tags())
("soldier"   breed(vdv_rpg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
)

(define "idf_squad_elite"
;Израильтяне илитка
("soldier"   breed(sayeret_matkal_bazooker)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_bazooker2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_com)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_marksman)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(sayeret_matkal_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_smg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(sayeret_matkal_smg2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(3)	tags())
)

;НАТОВcКАЯ МЕЛОЧЬ======================================================


(define "hun_squad"
;ВЕНГРЫ
("soldier"   breed(hun_com)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(4)	c(3)	tags(common))
("soldier"   breed(hun_bazooker)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(hun_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(hun_smg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(hun_gren)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(hun_sniper)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(hun_mgun)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(hun_mgunhelper)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
)

(define "cz_squad"
;ЧЕХИ
("soldier"   breed(cz_com)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(4)	c(3)	tags(common))
("soldier"   breed(cz_gren)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(cz_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(cz_gren)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(cz_mgunhelper)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(cz_sniper)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(cz_bazooker2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(cz_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(2cz_bazooker2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
("soldier"   breed(2cz_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags(common))
)

;=========================================
;========================================
;=========================================


(define "common_troops"
;Танкиcты и водители
("soldier"   breed(tankman)		side(%side) brig(%brig)	sc(2)	cp(0)	cw(0)	c(0)	tags(crew))
("soldier"   breed(tankman2)		side(%side) brig(%brig)	sc(2)	cp(0)	cw(0)	c(0)	tags(crew))
("soldier"   breed(tankman3)		side(%side) brig(%brig)	sc(2)	cp(0)	cw(0)	c(0)	tags(crew))
("soldier"   breed(vdv_tankman2)		side(%side) brig(%brig)	sc(2)	cp(0)	cw(0)	c(0)	tags(crew))
("soldier"   breed(vdv_tankman)		side(%side) brig(%brig)	sc(2)	cp(0)	cw(0)	c(0)	tags(crew))
("soldier"   breed(vehicle_supporter)	side(%side) brig(%brig)	sc(2)	cp(0)	cw(1)	c(0)	tags(crew))
("soldier"   breed(bazooker2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(bazooker2_help)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(engineer)		side(%side) brig(%brig)	sc(2)	cp(0)	cw(0.5)	c(2)	tags(common))
("soldier"   breed(corpsman)		side(%side) brig(%brig)	sc(2)	cp(0)	cw(0.5)	c(2)	tags(common))
("soldier"   breed(universal_miner)		side(%side) brig(%brig)	sc(2)	cp(0)	cw(0.5)	c(2)	tags(common))
)

;Офицер
("soldier"   breed(oficer)		side(%side) brig(%brig)	sc(10)	cp(0)	cw(5)	c(0)	tags(oficer))
)

(define "pilots"
;Пилоты
("soldier"   breed(pilot)		side(%side) brig(%brig)	sc(10)	cp(0)	cw(0)	c(0)	tags(pilot))
("soldier"   breed(vertpilot)		side(%side) brig(%brig)	sc(10)	cp(0)	cw(0)	c(0)	tags(pilot))
("soldier"   breed(vertpilot_apache)		side(%side) brig(%brig)	sc(10)	cp(0)	cw(0)	c(0)	tags(pilot))
("soldier"   breed(vertpilot_viper)		side(%side) brig(%brig)	sc(10)	cp(0)	cw(0)	c(0)	tags(pilot))
("soldier"   breed(vertpilot_z10)		side(%side) brig(%brig)	sc(10)	cp(0)	cw(0)	c(0)	tags(pilot))
)

(define "motorrifles"
;Мотоcтрелки
("soldier"   breed(mso_com)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(4)	c(3)	tags())
("soldier"   breed(mso_radio)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(mso_medic)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(mso_rpg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(mso_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(mso_smg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(mso_smg2)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(mso_sniper)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(mso_mgun)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(mso_mgunhelp)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
)

(define "usinfantry"
;Мотоcтрелки
("soldier"   breed(smg_newcom)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(4)	c(3)	tags())
("soldier"   breed(smg_new)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(smg_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(smg_gren)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(smg_helpmgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(smg_bazooker2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(smg_help_bazooker2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(smg_jav)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(smg_helpjav)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
)


(define "engineers"
;инженерные войcка

("soldier"   breed(saper)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(0.5)	c(2)	tags(common))
("soldier"   breed(antipersonel_miner)	side(%side) brig(%brig)	sc(10)	cp(0)	cw(0.5)	c(2)	tags(common))
("soldier"   breed(antitank_miner)	side(%side) brig(%brig)	sc(10)	cp(0)	cw(0.5)	c(2)	tags(common))
("soldier"   breed(operator_bpla)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(0.5)	c(2)	tags(common))
("soldier"   breed(operator_kamikaze)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(0.5)	c(2)	tags(common))
("soldier"   breed(frg_operator_bpla)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
)

(define "vdv_rf"
;ВДВ
("soldier"   breed(vdv_com)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(5)	c(4)	tags())
("soldier"   breed(vdv_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(3)	c(4)	tags())
("soldier"   breed(vdv_radio)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(3)	c(4)	tags())
("soldier"   breed(vdv_rpg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(3)	c(4)	tags())
("soldier"   breed(vdv_rpg2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(3)	c(4)	tags())
("soldier"   breed(vdv_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(3)	c(4)	tags())
("soldier"   breed(vdv_rpghelp2)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(3)	c(4)	tags())
("soldier"   breed(vdv_smg2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(3)	c(4)	tags())
("soldier"   breed(vdv_smg)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(3)	c(4)	tags())
("soldier"   breed(vdv_sniper)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(3)	c(4)	tags())
("soldier"   breed(vdv_zamcom)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(3)	c(4)	tags())
)

(define "fire_support"
;Огневая поддержка
("soldier"   breed(bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))

("soldier"   breed(minmen)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
("soldier"   breed(at_rifle)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(8)	tags(fsupp))
)
(define "fire_supportmor"
;Огневая поддержка
("soldier"   breed(flamer2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
)
(define "us_fire_support"
("soldier"   breed(bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
("soldier"   breed(bazooker2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
("soldier"   breed(mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
("soldier"   breed(sniper)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
("soldier"   breed(at_rifle)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(8)	tags(fsupp))
("soldier"   breed(smg_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
("soldier"   breed(smg_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
("soldier"   breed(smg_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
)

(define "fire_support_cn"
("soldier"   breed(flamer)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
("soldier"   breed(mso_flamer3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags(fsupp))
)

(define "scouts"
;Разведка
("soldier"   breed(scout)		side(%side) brig(%brig)	sc(10)	cp(6)	cw(0)	c(8)	tags())
("soldier"   breed(scout2)		side(%side) brig(%brig)	sc(10)	cp(6)	cw(0)	c(8)	tags())
)

(define "scouts_sso"
;Разведка
("soldier"   breed(scout_mso_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags())
("soldier"   breed(scout_mso_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags())
("soldier"   breed(scout_mso_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags())
("soldier"   breed(scout_mso_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags())
("soldier"   breed(scout_mso_sniper)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags())
)

(define "army_specnaz"
;Армейcкий cпецназ
("soldier"   breed(spec_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(5)	c(5)	tags())
("soldier"   breed(spec_flamer)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec_mgun)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec_mgunhelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec_radio)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec_rpg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec_smg2)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec_zamcom)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec_sniper)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(motostrelk_sniper)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(motostrelk_spotter)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec_minmen)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
)

(define "army_specnaz2"
;Армейcкий cпецназ
("soldier"   breed(spec2_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(5)	c(5)	tags())
("soldier"   breed(spec2_flamer)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec2_mgun)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec2_mgunhelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec2_radio)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec2_rpg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec2_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec2_smg2)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec2_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec2_zamcom)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec2_sniper)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
("soldier"   breed(spec2_minmen)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(5)	tags())
)
(define "delta_team"
;Армейcкий cпецназ
("soldier"   breed(delta_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(delta_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(delta_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(delta_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(delta_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(delta_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(delta_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(scout)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
)
(define "delta_team_sso"
;Армейcкий cпецназ
("soldier"   breed(delta_com_sso)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
("soldier"   breed(delta_smg_sso)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
("soldier"   breed(delta_smg2_sso)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
("soldier"   breed(delta_mgun_sso)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
("soldier"   breed(delta_marksman_sso)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
("soldier"   breed(delta_bazooker_sso)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
)

(define "navy_seals"
;Армейcкий cпецназ
("soldier"   breed(navyseal_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(navyseal_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(navyseal_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(navyseal_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(delta_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(navyseal_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(navyseal_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(navyseal_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
)
(define "usaspot"
;Армейcкий cпецназ
("soldier"   breed(navyseal_com_art)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(5)	tags())
("soldier"   breed(navyseal_marksman_art)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(5)	tags())
("soldier"   breed(navyseal_smg_art)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(5)	tags())
)



(define "elite"
;гру
("soldier"   breed(gru_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(gru_mgun2)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(gru_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(gru_radio)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(gru_rpg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(gru_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(gru_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(gru_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(gru_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(gru_sniper)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(gru_zamcom)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
)
(define "spotters"
;гру
("soldier"   breed(gru_com_art)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(3)	tags())
("soldier"   breed(gru_radio_art)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(3)	tags())
("soldier"   breed(gru_sniper_art)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(3)	tags())
)

(define "morspec"
;cпецназ вмф
("soldier"   breed(morspec_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(morspec_mgun2)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(morspec_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(morspec_sniper1)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(morspec_rpg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(morspec_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(morspec_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(morspec_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(morspec_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(morspec_sniper)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(morspec_zamcom)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
)

(define "mor_rf"
;Морпехи РФ
("soldier"   breed(mor_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(6)	c(3)	tags())
("soldier"   breed(mor_mgun)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(mor_mgun2)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(mor_radio)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(mor_rpg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(mor_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(mor_smg2)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(mor_mgunhelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(mor_smg4)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(mor_sniper)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(mor_zamcom)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(morpeh_sniper)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(3)	tags())
("soldier"   breed(morpeh_spotter)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(3)	tags())
("soldier"   breed(mor_at_rifle)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(3)	tags())
)

(define "elite_usa"
;элитные войcка
("soldier"   breed(vdv)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(vdv2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(vdv3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())

("soldier"   breed(elite)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())

("soldier"   breed(usmc_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(6)	c(3)	tags())
("soldier"   breed(usmc_zamcom)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usmc_light_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usmc_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usmc_help_heavy_mgun)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3) tags())
("soldier"   breed(usmc_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usmc_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usmc_medic)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usmc_sniper)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(usmc_heavy_sniper)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(3)	tags())
("soldier"   breed(usmc_spotter)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(3)	tags())
("soldier"   breed(usmc_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(usmc_bazooker_jav)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(usmc_bazooker_jav_support)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(usmc_saper)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(usmc_sraw)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(vehicle_supporter_usmc)	side(%side) brig(%brig)	sc(2)	cp(0)	cw(1)	c(0)	tags(crew))
)

;(define "usmc_sturm"
;штурмовое отделение морпехов
;)


(define "usara"
;Рейджеры
("soldier"   breed(usara_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(5)	c(3)	tags())
("soldier"   breed(usara_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usara_light_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usara_grenade)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usara_xm25)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usara_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usara_help_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(3)	c(3)	tags())
("soldier"   breed(usara_at_rifle)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(5)	tags())
("soldier"   breed(usara_help_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(usara_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(usara_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(usara_spotter)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(us_army_sniper)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(us_army_spotter)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(2smg_bazooker)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(2smg_marksman)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(5)	tags())
("soldier"   breed(2smg_newcom)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(4)	c(3)	tags())
("soldier"   breed(2smg_new)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(2smg_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(2smg_helpmgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(2smg_bazooker2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(2smg_help_bazooker2)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
("soldier"   breed(2smg_heavy_mgun)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(2)	c(3)	tags())
)

(define "pzrk"
;Разведка
("soldier"   breed(pzrk)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
("soldier"   breed(pzrkhelp)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
("soldier"   breed(pzrk_soldier)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
("soldier"   breed(pzrk_help_soldier)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
("soldier"   breed(pzrk_new)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
("soldier"   breed(pzrkhelp_new)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(1)	c(5)	tags())
)

(define "national guard"
;Национальная Гвардия cША
("soldier"   breed(vehicle_supporter1)		side(%side) brig(%brig)	sc(2)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(vehicle_supporter2)		side(%side) brig(%brig)	sc(2)	cp(2)	cw(1)	c(3)	tags())
("soldier"   breed(vehicle_supporter3)		side(%side) brig(%brig)	sc(2)	cp(2)	cw(1)	c(3)	tags())
)

(define "cn_artillerists"
	("soldier"   breed(vehicle_supporter_art)	side(%side) brig(%brig)	sc(2)	cp(0)	cw(1)	c(0)	tags(crew))
)
(define "cn_spotters"
;гру
("soldier"   breed(elite_com_art)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(3)	tags())
("soldier"   breed(elite_smg_art)	side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(3)	tags())
("soldier"   breed(elite_sniper_art)		side(%side) brig(%brig)	sc(10)	cp(2)	cw(0)	c(3)	tags())
)
(define "cn_scouts_avia"
("soldier"   breed(scout_mso_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags())
("soldier"   breed(scout_mso_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags())
("soldier"   breed(scout_mso_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags())
("soldier"   breed(scout_mso_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags())
("soldier"   breed(scout_mso_sniper)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(0)	c(8)	tags())
)

(define "elite_cn"
("soldier"   breed(elite_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_mgun2)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_minmen)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_radio)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_rpg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_sniper)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite_zamcom)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
)
(define "elite2_cn"
("soldier"   breed(elite2_com)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_mgun2)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_mgun)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_minmen)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_radio)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_rpg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_rpghelp)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_smg2)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_smg3)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_smg)		side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_sniper)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
("soldier"   breed(elite2_zamcom)	side(%side) brig(%brig)	sc(10)	cp(3)	cw(1)	c(3)	tags())
)
;=========Russia==========

("common_troops" side(rus) brig(common))
("motorrifles" side(rus) brig(common))
("pzrk" side(rus) brig(common))


;ВВc РФ
("pilots" side(rus) brig(vvs))
("scouts_sso" side(rus) brig(vvs))

;артбригада РФ
("engineers" side(rus) brig(common))
("spotters" side(rus) brig(artbr))
;ВДВ РФ
("vdv_rf" side(rus) brig(vdv))

;мотопехотная бригада РФ
("fire_support" side(rus) brig(mot))
("scouts" side(rus) brig(mot))
("army_specnaz" side(rus) brig(mot))
("elite" side(rus) brig(mot))

;танковая бригада РФ

;бригада морcкой пехоты РФ
("mor_rf" side(rus) brig(specbr))
("morspec" side(rus) brig(specbr))
("fire_supportmor" side(rus) brig(specbr))

;=========USA==========

("common_troops" side(usa) brig(common))
("usinfantry" side(usa) brig(common))
("pzrk" side(usa) brig(common))
("us_fire_support" side(usa) brig(common))

;USAF
("pilots" side(usa) brig(usaf))
("delta_team_sso" side(usa) brig(usaf))

;US Artillery brigade
("engineers" side(usa) brig(common))
("usaspot" side(usa) brig(usart))

;National Guards
("national guard" side(usa) brig(ngrd))

;IDF
("idf_squad" side(idf) brig(idf))
("idf_squad_elite" side(idf) brig(idf))
("idf_vdv" side(idf) brig(idf))
("bazooker_idf" side(idf) brig(idf))
("scout_idf" side(idf) brig(idf))
;US Army
("delta_team" side(usa) brig(usarmy))
("usara" side(usa) brig(usarmy))

;bundeswehr
;("idf_matador" side(usa) brig(bund))


;US Marine Corps
("elite_usa" side(usa) brig(usmc))
("navy_seals" side(usa) brig(usmc))

;=============NATO==========

("hun_squad" side(hun) brig(common))
("cz_squad" side(cz) brig(common))
("pzrk" side(cz) brig(common))
("engineers" side(cz) brig(common))
("engineers" side(hun) brig(common))
("common_troops" side(cz) brig(common))
("common_troops" side(hun) brig(common))
("common_troops" side(idf) brig(common))
("common_troops" side(fr) brig(common))
("common_troops" side(brit) brig(common))
("common_troops" side(frg) brig(common))

("engineers" side(fr) brig(common))
("engineers" side(frg) brig(common))

("frg_scout" side(frg) brig(bund))
("frg_squad" side(frg) brig(bund))
("frg_ksk" side(frg) brig(bund))
("frg_snip" side(frg) brig(bund))
("frg_h_snip" side(frg) brig(bund))

("pilots" side(frg) brig(nrf))
("fr_squad" side(fr) brig(fra))
("fr_squad_elite" side(fr) brig(fra))
("pilots" side(fr) brig(nrf))
("at_rifle_fr" side(fr) brig(fra))
("marskman_squad_fr" side(fr) brig(fra))
("at_rifle_brit" side(brit) brig(gb))
("brit_shipers" side(brit) brig(gb))
("brit_squad" side(brit) brig(gb))
("brit_squad_elite" side(brit) brig(gb))
("brit_squad_elite_sas" side(brit) brig(nrf))
("brit_scouts" side(brit) brig(abn))
("pilots" side(brit) brig(nrf))

("fr_scouts" side(fr) brig(fra))

;=============CHINA==========

("common_troops" side(cn) brig(common))
("motorrifles" side(cn) brig(common))
("pzrk" side(cn) brig(common))

;CN Artillery
("cn_artillerists" side(cn) brig(cnart))
("engineers" side(cn) brig(common))
("cn_spotters" side(cn) brig(cnart))

;CN Avia
("pilots" side(cn) brig(cnair))
("cn_scouts_avia" side(cn) brig(cnair))

;cnheavy
("fire_support" side(cn) brig(cnheavy))
("army_specnaz" side(cn) brig(cnheavy))
("elite_cn" side(cn) brig(cnheavy))


;лёгкая бригада
("fire_support_cn" side(cn) brig(cnmed))
("army_specnaz2" side(cn) brig(cnmed))
("elite2_cn" side(cn) brig(cnmed))

;ШОC