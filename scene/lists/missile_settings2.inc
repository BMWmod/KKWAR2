;=============================================================================================
;Дальность ЗУР, ВВ	slow	normal	fast
;					7,5м/шаг	10м/шаг	10м/шаг
;всего				300м	400м	400м
;плюс 10 проц для SAM, плюс 2 шага для вертикалок.
;для SAM запас на маневр не делается, дальность стрельбы ботом меньше топливной на 5проц, и это учитывается в сете
;дальности округляются по правилам математики, а не в большую сторону.
;Дальность ATGM и AGM	slow	normal	fast
;						5.75м/шаг	7,5м/шаг	7,5м/шаг
;всего					200м	300м	300м
;плюс 10 проц. на маневр (это около 14м)
;5,75м/шаг - это с учетом дрейфа, реально 5 м/шаг

;Коэффициенты скоростей.
;Реальные скорости ракет - 1 шаг за 0,24с у slow и 0,16 у других. 
;1 шаг - это 5.75м у slow ПТУР и ВЗ, 7,5м у normal, fast ПТУР и ВЗ, 
;7,5м у slow ВВ, 10м у normal, fast ВВ. Итоговая скорость по умолчанию c K=1
;			slow		normal		fast
;ПТУР, ВЗ	20.8 м/с	35,2 м/с	46,9 м/с
;ВВ 		31,25 м/с	46,9 м/с	62,5 м/с

;K - коэффициент ускорения или замедления, K=1.2 значит, что ракета летит на 20% быстрее
;Диапазоны slow normal fast
;			slow	slow	slow	normal	normal	normal	fast	fast
;			min		k=1		max		min		k=1		max		min		k=1,max
;ПТУР, ВЗ	20.0	20.8	28.0	28.1	35,2	41.0	41.1	46,9
;ВВ 		25.0	31,25	39.0	39.1	46,9	54.7	54.8	62,5
;Используем ("speed_slow" coeff(K)) ("speed_normal" coeff(K)) ("speed_fast" coeff(K))
;в соотв. с указанным в дефе классом скорости для точной настройки.
;Нельзя выходить за диапазоны, нельзя ставить K более 1 для fast
;Нельзя разгонять более чем на 30% (slow) и 20-25 (normal).
;Дл экономии длины кода speed не пишется, если находится от 0,95 до 1,05.

;missilename(reflex) - название дефа ракеты и карриера (карриер идет с суффиксом _carrier)
;rotation(1) - вращается в полете
;rand_move(1) - смещается вокруг оси прицеливания
;smoke_vulnerable(1) - в дыму терет управление
;decoyprob(0.1) - помехозащищенность. Меньше значение - меньше шанс ухода на ловушки.
;range(22) - дальность, см выше. для CWPS_proj_2stage - 40+число, для CWPS_proj_3stage - 80+число
;tail(proj_jet_small) - тип эффекта двигателя
;eng_time(1) - время работы эффекта двигателя
;=============================================================================================
;для импульсных ракет указывается полетное время flight_time и параметры тяги vel imp. Они рассчитываются таблицей xls.

;===============Ракеты армии и ВВС
{("CWPS_impulse_proj" missilename(48n6) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0)  vel(28) imp(55) flight_time(8.2) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(48n6e2) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0)  vel(28) imp(55) flight_time(8.2) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj_eject_slow" missilename(9k14m)  rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(10) imp(17) flight_time(7) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_malutka) bone(tail))("cm_jet" dmg(460))}
{("CWPS_impulse_proj" missilename(9k31) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.8) vel(21) imp(37) flight_time(3.7) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(9k37) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.20) vel(23) imp(42) flight_time(3.6) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(9k333) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.4) vel(24) imp(43) flight_time(3.5) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(9k111) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(24) flight_time(4.2) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))("cm_jet" dmg(460))}
{("CWPS_impulse_proj" missilename(9k111m) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(24) flight_time(4.6) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))("cm_jet" dmg(460))}
{("CWPS_impulse_proj" missilename(9k113) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5.1) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))("cm_jet" dmg(600))}
{("CWPS_impulse_proj" missilename(9k113m) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5.1) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))("cm_jet" dmg(750))}
{("CWPS_impulse_proj" missilename(9k113m1) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5.1) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))("cm_jet" dmg(800))}
{("CWPS_impulse_proj" missilename(9k115-1_cm) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(14) imp(23) flight_time(4.1) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_metis) bone(tracer))("cm_jet" dmg(850))}
{("CWPS_impulse_proj" missilename(9k115-2_cm) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(14) imp(23) flight_time(4.4) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_metis) bone(tracer))("cm_jet" dmg(950))}
{("CWPS_impulse_proj" missilename(9m38) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.36) vel(28) imp(51) flight_time(6.5) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(9m114f) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(28) imp(51) flight_time(7.2) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(9m114m) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(10) imp(17) flight_time(7) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(650))}
{("CWPS_impulse_proj" missilename(9m117) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(19) imp(34) flight_time(4.4) tail(proj_jet_small) eng_time(1))("cm_jet" dmg(750))}
{("CWPS_impulse_proj" missilename(9m117m) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(19) imp(34) flight_time(4.4) tail(proj_jet_small) eng_time(1))("cm_jet" dmg(600))}
{("CWPS_impulse_proj" missilename(9m117_115) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(19) imp(34) flight_time(3.9) tail(proj_jet_small) eng_time(1))("cm_jet" dmg(600))}
{("CWPS_impulse_proj" missilename(9m117cn) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(19) imp(34) flight_time(3.9) tail(proj_jet_small) eng_time(1))("cm_jet" dmg(600))}
{("CWPS_impulse_proj" missilename(9m117cn100) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(19) imp(34) flight_time(3.9) tail(proj_jet_small) eng_time(1))("cm_jet" dmg(600))}
{("CWPS_impulse_proj" missilename(9m119m) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(20) imp(36) flight_time(4.1) tail(proj_jet_small) eng_time(1))("cm_jet" dmg(850))}
{("CWPS_impulse_proj" missilename(9m119m1) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(66) vel(20) imp(36) flight_time(4.1) tail(proj_jet_small) eng_time(1))("cm_jet" dmg(900))}
{("CWPS_impulse_proj" missilename(9m120f) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(90) vel(23) imp(41) flight_time(3.9) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(9m120m) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(90) vel(23) imp(41) flight_time(3.9) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(950))}
{("CWPS_impulse_proj" missilename(9m133_fg) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(30) flight_time(5.8) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m133_1_cm) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(29) flight_time(5.6) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(1200))}
{("CWPS_impulse_proj" missilename(9m133_cm) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(29) flight_time(5.1) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(1300))}
{("CWPS_impulse_proj" missilename(9m133_tb) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(29) flight_time(5.6) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m311) rotation(0) rand_move(1) smoke_vulnerable(1) decoyprob(0.43) vel(28) imp(53) flight_time(3.1) tail(proj_jet_sam) eng_time(0.7))
	{on "launch_procedures"
		{delay 0.7 
			{with_linked_entity "missile"
			 {view pause "proj_jet"}
			 {view stop "proj_jet"}
			 {view hide "proj_jet"}
			 {tear "piece_missile_booster" bone "starter"{impulse forward 25}}
			}
		}		
	}
}
{("CWPS_impulse_proj" missilename(9m317) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.30) vel(28) imp(51) flight_time(7.2) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(9m330) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.45) vel(27) imp(49) flight_time(4) tail(proj_jet_sam) eng_time(5))}
{("CWPS_impulse_proj" missilename(9m338) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.40) vel(28) imp(55) flight_time(4.2) tail(proj_jet_sam) eng_time(5)))}
{("CWPS_impulse_proj" missilename(adats) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(28) imp(55) flight_time(3.2) tail(proj_jet_sam) eng_time(3)) ("cm_jet" dmg(900))}
{("CWPS_impulse_proj" missilename(aim-120c7) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(55) flight_time(6.4) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj_airdropped" missilename(aim-120c7_drop) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.4)  vel(28) imp(55) flight_time(6.4) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(aim-120c7_nasams) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(55) flight_time(4.9) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(aim7m) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.60) vel(28) imp(55) flight_time(4.6) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(aim7m_air) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.60) vel(28) imp(55) flight_time(4.6) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(aim-9l) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.20) vel(28) imp(51) flight_time(3.7) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(ag300m) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(29) flight_time(8.4) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(1100))}
{("CWPS_impulse_proj" missilename(agm-65d) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.15) vel(17) imp(30) flight_time(9.9) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(660))}
{("CWPS_impulse_proj" missilename(agm-65g) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(30) flight_time(9.9) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(agm-84d) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(16) imp(28) flight_time(16.1) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(agm88) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(26) imp(45) flight_time(8.9) tail(proj_jet_atgm) eng_time(3))
	{on "top_attack"
		{delay 0.7 {call "detonate"}}
	}
}
{("CWPS_impulse_proj" missilename(agm-114k) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj" missilename(agm-114k2) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj" missilename(agm-114l) rotation(0) rand_move(0) smoke_vulnerable(0.5) decoyprob(0.3) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj" missilename(agm-114n) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.15) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(agm-114r) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(600))}
{("CWPS_impulse_proj_airdropped" missilename(agm-154) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(15) imp(25) flight_time(15) tail(none) eng_time(0.1))
	{on "top_attack" overload
		{delay 1.0 
			{volumes disable all}
			{spawn "agm-154_impactor" "missile_point" x
				{ani_wind "on_start"  end}
				{impulse up 0.1 forward 30 com}{gravity 0.2}
				{ani_play "cargo"}
				{volumes disable all}
				{delay 1.1 {volumes disable all} {spawn "agm-154_cluster" offset 0 0 -15}}
				{delay 1.6 {spawn "agm-154_cluster" offset 0 0 -15}}
				{delay 2.1 {spawn "agm-154_cluster" offset 0 0 -15}}
				{delay 2.2 {spawn "aero_die_particle"}{delete}}
			}
			{delete}
		}
	}
}
{("CWPS_impulse_proj_eject" missilename(akd-10) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(11) imp(19) flight_time(8) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(1400))}
{("CWPS_impulse_proj" missilename(alarm_missile) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(27) imp(47) flight_time(8.2) tail(proj_jet_atgm) eng_time(3))
	{on "top_attack"
		{delay 0.7 {call "detonate"}}
	}
}
{("CWPS_impulse_proj" missilename(brimstone) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.1) vel(21) imp(38) flight_time(5.8) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(1200))}
{("CWPS_impulse_proj_airdropped" missilename(c802akg) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(17) imp(29) flight_time(15.8) tail(proj_jet_small) eng_time(3))
	{on "link_effects1"
	  {ani_play "top_attack_off" 1}
	}
	{on "top_attack"
		{delay 0.9 {call "detonate"}}
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(ch901) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(5.5) tail(none) eng_time(1))}
{("CWPS_impulse_proj" missilename(eryx_rock) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(2.6) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(900))}

{("CWPS_impulse_proj" missilename(fim-92a) rotation(1) rand_move(0) smoke_vulnerable(0) decoyprob(0.25) vel(27) imp(49) flight_time(2.8) tail(proj_jet_sam) eng_time(1.5))}
{("CWPS_impulse_proj" missilename(fn6a_ammo) rotation(1) rand_move(0) smoke_vulnerable(0) decoyprob(0.2) vel(25) imp(44) flight_time(3.4) tail(proj_jet_sam) eng_time(1.5))}
{("CWPS_impulse_proj" missilename(germes) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.1) vel(28) imp(55) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))
	{on "launch_procedures"
		{delay 1 
			{with_linked_entity "missile"
			 {view pause "proj_jet"} {view stop "proj_jet"} {view hide "proj_jet"}
			 {tear "piece_missile_booster" bone "starter"{impulse forward 25}}
			}
		}		
	}
}
{("CWPS_impulse_proj" missilename(hellfire) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.3) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj" missilename(hj8e) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(14) imp(24) flight_time(5.4) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))("cm_jet" dmg(750))}
{("CWPS_impulse_proj" missilename(hj8h) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(14) imp(24) flight_time(5.4) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))("cm_jet" dmg(750))}
{("CWPS_impulse_proj" missilename(hj8f) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(14) imp(24) flight_time(5.4) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))("cm_jet" dmg(90))};not 900 but 90.
{("CWPS_impulse_proj" missilename(hj9_missile) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5.6) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))("cm_jet" dmg(850))}


{("CWPS_impulse_proj_eject_slow" missilename(hj73c) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(10) imp(17) flight_time(7) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_malutka) bone(tail))("cm_jet" dmg(500))}

{("CWPS_impulse_proj" missilename(hq7b) rotation(0) rand_move(1) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(53) flight_time(4.3) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(hq16a_missile) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.30) vel(28) imp(55) flight_time(6.4) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(hq16b_missile) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.30) vel(28) imp(55) flight_time(7.3) tail(proj_jet_sam) eng_time(4)) }
{("CWPS_impulse_proj" missilename(hot_rock) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5.1) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(1300))}	
{("CWPS_impulse_proj" missilename(igla_s) rotation(1) rand_move(0) smoke_vulnerable(0) decoyprob(0.25) vel(25) imp(44) flight_time(3.5) tail(proj_jet_sam) eng_time(1.5))}
{("CWPS_impulse_proj" missilename(jav_rock) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.5) vel(12) imp(20) flight_time(5.4) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(750))}
{("CWPS_impulse_proj" missilename(javf_rock) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.5) vel(12) imp(20) flight_time(6.2) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(750))}
{("CWPS_proj" missilename(krasnopol) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.0) range(40) tail() eng_time(0))("speed_fast" coeff(1.0))
    {on "link_effects" overload
    }
}
{("CWPS_impulse_proj_airdropped" missilename(jsm) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(17) imp(31) flight_time(15.7) tail(proj_jet_atgm) eng_time(3))
	{on "top_attack"	
		{delay 0.9 {call "detonate"}}
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(lahat) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.2) vel(16) imp(28) flight_time(5.4) tail(proj_jet_small) eng_time(1))("cm_jet" dmg(800))}
{("CWPS_impulse_proj" missilename(lancet3m_fg) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(5.5) tail(none) eng_time(1))}
{("CWPS_impulse_proj" missilename(lancet3m_cm) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(5.5) tail(none) eng_time(1))("cm_jet" dmg(215))}
(define "lancet_impactor"
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				{volumes enable contact contact_ground}
				{call "check_delete_part"}
			}
		)
		{on "detonate" overload
			{if rand 0.5 ("cut_part" args "WingL1")}
			{if rand 0.5 ("cut_part" args "WingL2")}
			{if rand 0.5 ("cut_part" args "WingR1")}
			{if rand 0.5 ("cut_part" args "WingR2")}
			{if altitude 0
			 {spawn "proj_restrictor" "root" x}
			 {delay 0.05 {stuff_detonate}}
			  else   			  
				{gravity 0}
				{impulse up 2.0}
				{call "underground_detonate"}
			}
		}
		{on "delete" overload
			{if rand 0.5 ("cut_part" args "wingl1")}
			{if rand 0.5 ("cut_part" args "wingl2")}
			{if rand 0.5 ("cut_part" args "wingr1")}
			{if rand 0.5 ("cut_part" args "wingr2")}
			{delay 0.01 {delete}}
		}
)
{"lancet3m_fg_impactor"
	("lancet_impactor")
}
{"lancet3m_cm_impactor"
	("lancet_impactor")
	("cm_jet" dmg(215))
}
{("CWPS_impulse_proj" missilename(ld10) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(28) imp(55) flight_time(7.3) tail(proj_jet_atgm) eng_time(2))
	{on "top_attack"
		{delay 0.7 {call "detonate"}}
	}
}
{("CWPS_impulse_proj" missilename(m47dragon_rock) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(13) imp(21) flight_time(4) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(610))}
{("CWPS_impulse_proj" missilename(milan_rock) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(13) imp(22) flight_time(4.6) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(880))}
{("CWPS_impulse_proj" missilename(milan-er) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(13) imp(22) flight_time(5.4) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj" missilename(mistral_missile) rotation(1) rand_move(0) smoke_vulnerable(0) decoyprob(0.1) vel(28) imp(53) flight_time(2.6) tail(proj_jet_sam) eng_time(1.5))}
{("CWPS_impulse_proj" missilename(mmp_missile) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(11) imp(18) flight_time(7.8) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj" missilename(nlaw_rocket) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(13) imp(21) flight_time(3.6) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_tow) bone(tail))
	{on "stuff_detonate" overload
		{if not tagged "stuff_detonate"
			{tags add "stuff_detonate"}
			{volumes disable all}
			{with_linked_entity "missile" {call "delete"}}
			{spawn "nlaw_rocket_impactor" "missile_point" x
				{impulse up 0.1 forward 20 com}
				{delay 0.03 {spawn "nlaw_core" {impulse up -40 forward 0.1 com}{volumes disable blast}}}
				{delay 0.1 {stuff_detonate}}
			}
			{delay 0 {delete}}
		}
	}
}
{("CWPS_impulse_proj" missilename(osa_missile) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.51) vel(23) imp(41) flight_time(4) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(patriot) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.36) vel(28) imp(55) flight_time(7.6) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(pantsir_57e6e) rotation(0) rand_move(1) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(55) flight_time(4.8) tail(proj_jet_sam) eng_time(2.5))
	{on "launch_procedures"
		{delay 1.0 
			{with_linked_entity "missile"
			 {view pause "proj_jet"}
			 {view stop "proj_jet"}
			 {view hide "proj_jet"}
			 {tear "piece_missile_booster" bone "starter"{impulse forward 25}}
			}
		}		
	}
}

{("CWPS_impulse_proj_airdropped" missilename(pbk-500u) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(15) imp(25) flight_time(13.9) tail(none) eng_time(0.1))
    (define "spread_pbk"
	{delay %delay (* 0.5 %delay) {spawn "spbe-d" offset %x %y 0}}
	)
	{on "top_attack" overload
	  {delay 1.1
		{volumes disable all}
		{spawn "pbk-500u_impactor" "missile_point" x
			{volumes disable all}
			{impulse up 0.1 forward 30 com}{gravity 0.2}
			("spread_pbk" delay(0.3) x(0) y(0))
		    ("spread_pbk" delay(0.3) x(250) y(0))
		    ("spread_pbk" delay(0.3) x(-250) y(0))
		    ("spread_pbk" delay(0.3) x(0) y(250))
		    ("spread_pbk" delay(0.3) x(0) y(-250))
		    ("spread_pbk" delay(0.3) x(250) y(250))
		    ("spread_pbk" delay(0.3) x(250) y(-250))
		    ("spread_pbk" delay(0.3) x(-250) y(-250))
		    ("spread_pbk" delay(0.3) x(-250) y(250))
		    ("spread_pbk" delay(0.3) x(450) y(0))
		    ("spread_pbk" delay(0.3) x(-450) y(0))
		    ("spread_pbk" delay(0.3) x(0) y(450))
		    ("spread_pbk" delay(0.3) x(0) y(-450))
		    ("spread_pbk" delay(0.3) x(450) y(-600))
		    ("spread_pbk" delay(0.3) x(-450) y(600))
			{delay 2.0 {spawn "aero_die_particle"}{delete}}
		}
		{delete}
	  }
	}
}
{("CWPS_impulse_proj" missilename(pl5e2) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.30) vel(28) imp(51) flight_time(3.7) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(pl8b) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.25) vel(28) imp(55) flight_time(4.2) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(pl12) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.3) vel(28) imp(55) flight_time(5.7) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(r-3c) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.7) vel(24) imp(43) flight_time(3.7) tail(proj_jet_sam) eng_time(2)) }
{("CWPS_impulse_proj" missilename(r_27er) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.45) vel(150) vel(28) imp(55) flight_time(5.2) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj_airdropped" missilename(r_27er_drop) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.45) vel(28) imp(55) flight_time(5.2) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(r60_su25) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.4) vel(28) imp(51) flight_time(3) tail(proj_jet_sam) eng_time(2))}
{("CWPS_impulse_proj" missilename(r-73) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.30) vel(28) imp(51) flight_time(3.5) tail(proj_jet_sam) eng_time(2)) }
{("CWPS_impulse_proj_airdropped" missilename(rvv-ae) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(55) flight_time(5.4) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(rvv-sd) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(55) flight_time(5.7) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj_airdropped" missilename(rvv-sd_drop) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(55) flight_time(5.7) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(rvv-md) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.20) vel(28) imp(51) flight_time(3.5) tail(proj_jet_sam) eng_time(2))}
{("CWPS_impulse_proj" missilename(red_arrow_10b) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(13) imp(21) flight_time(8) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(1300))
	{on "launch_procedures"
		{delay 0.1 {with_linked_entity "missile" {ani_play "on_start"}}}
	}
}
{("CWPS_impulse_proj" missilename(red_arrow12_rock) rotation(0) rand_move(0) smoke_vulnerable(0.5) decoyprob(0.5) vel(12) imp(20) flight_time(6.2) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(700))}
{("CWPS_impulse_proj" missilename(rim116) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.25) vel(26) imp(46) flight_time(3.7) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(sampt) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.36) vel(28) imp(55) flight_time(7.7) tail(proj_jet_atgm) eng_time(3))
	{on "launch_procedures"
;		{if  not tagged "cwps_not_first_stage" 
			{delay 0.02 {with_linked_entity "missile" 
				{add_view	"proj_jet_sam"			"proj_jet1"			"tail1"}
				{view start "proj_jet1"}
				{view show "proj_jet1"}
			}}
;		}
		{delay 1.5 
;		      {if tagged "cwps_extended_range"
				{with_linked_entity "missile"
					{view pause "proj_jet1"}
					{view stop "proj_jet1"}
					{view hide "proj_jet1"}
					{tear "piece_missile_booster" bone "starter"{impulse forward 25}}
				}
;		       }
		}
	}
	{on "top_attack"
		{if not tagged "pifpaf"
			{tags add "pifpaf"}
			{with_linked_entity "missile"
				{add_view	"proj_jet"			"sidethrust1"			"sidethrust1"}
				{add_view	"proj_jet"			"sidethrust2"			"sidethrust2"}
				{add_view	"proj_jet"			"sidethrust3"			"sidethrust3"}
				{add_view	"proj_jet"			"sidethrust4"			"sidethrust4"}
				(define "pifpaf"
				  {delay 0.1 0.08
					{if rand 0.33 {view start "sidethrust%0"}{view show "sidethrust%0"} else
						{if rand 0.5 {view pause "sidethrust%0"}	{view hide "sidethrust%0"}}
					}
				  }
				)
				
				{delay 0.05 ("pifpaf" args 1)("pifpaf" args 2)("pifpaf" args 3)("pifpaf" args 4)}
				{delay 0.2  ("pifpaf" args 1)("pifpaf" args 2)("pifpaf" args 3)("pifpaf" args 4)}
				{delay 0.4  ("pifpaf" args 1)("pifpaf" args 2)("pifpaf" args 3)("pifpaf" args 4)}
				{delay 0.6  ("pifpaf" args 1)("pifpaf" args 2)("pifpaf" args 3)("pifpaf" args 4)}
				{delay 0.8  ("pifpaf" args 1)("pifpaf" args 2)("pifpaf" args 3)("pifpaf" args 4)}
				{delay 1  ("pifpaf" args 1)("pifpaf" args 2)("pifpaf" args 3)("pifpaf" args 4)}
			}
		}
	}
}
{("CWPS_impulse_proj" missilename(shahed136_base) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(7.5) tail(none) eng_time(1))}
{"shahed136_base_impactor_link" 	
	(define "cut_part"
		{tear "piece_medium_steel" bone %0
			{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			{volumes enable contact contact_ground}
			{call "check_delete_part"}
		}
	)
	{on "detonate" overload
		{if rand 0.3 ("cut_part" args "part1")}
		{if rand 0.3 ("cut_part" args "tail1")}
		{if rand 0.3 ("cut_part" args "tail2")}
	    {if altitude 0
		 {spawn "proj_restrictor" "root" x}
		 {delay 0.05 {stuff_detonate}}
		  else   			  
			{gravity 0}
			{impulse up 2.0}
			{call "underground_detonate"}
		}
	}
	{on "delete" overload
		{if rand 0.3 ("cut_part" args "part1")}
		{if rand 0.3 ("cut_part" args "tail1")}
		{if rand 0.3 ("cut_part" args "tail2")}
		{delay 0.01 {delete}}
	}
}
{("CWPS_impulse_proj" missilename(shershen_ammo_cm) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(15) imp(25) flight_time(5.8) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(850))}
{("CWPS_impulse_proj" missilename(shershen_ammo_fg) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(15) imp(25) flight_time(5.8) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj_airdropped" missilename(slam_er) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0)  vel(14) imp(24) flight_time(19.2) tail(proj_jet_sam) eng_time(3))
	{on "link_effects1"
	  {ani_play "top_attack_off" 1}
	}
	{on "top_attack"
		{delay 0.7 {call "detonate"}}
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(spike-lr) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(12) imp(20) flight_time(7.4) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(700))}
{("CWPS_impulse_proj" missilename(spike-sr) rotation(0) rand_move(0) smoke_vulnerable(0.5) decoyprob(0.3) vel(10) imp(17) flight_time(6) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(700))}
{("CWPS_impulse_proj" missilename(spike-er) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(12) imp(20) flight_time(8) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj" missilename(spike-er2) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(12) imp(20) flight_time(8.7) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj_eject" missilename(spike_nlos) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(15) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj_eject" missilename(spike_nlos_fg) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(15) tail(proj_jet_atgm) eng_time(2))}

{("CWPS_impulse_proj" missilename(sraw_rock) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(17) imp(29) flight_time(2.3) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_tow) bone(tail))
	{on "stuff_detonate" overload
		{if not tagged "stuff_detonate"
			{tags add "stuff_detonate"}
			{volumes disable all}
			{with_linked_entity "missile" {call "delete"}}
			{spawn "sraw_rock_impactor" "missile_point" x
				{impulse up 0.1 forward 20 com}
				{delay 0.03 {spawn "sraw_core" {impulse up -40 forward 0.1 com}{volumes disable blast}}}
				{delay 0.1 {stuff_detonate}}
			}
			{delay 0 {delete}}
		}
	}
}
{("CWPS_impulse_proj" missilename(starstreak_ammo) rotation(1) rand_move(0) smoke_vulnerable(0) decoyprob(0.01) vel(28) imp(55) flight_time(2.8) tail(proj_jet_sam) eng_time(0.5))("cm_jet" dmg(40))
	{on "launch_procedures"
		{with_linked_entity "missile"
			{tear "piece_missile_booster" bone "starter"{impulse forward 10}}
		}
		{volumes disable all}
		{delay 0.55 
			{with_linked_entity "missile"
				{view pause "proj_jet"}
				{view stop "proj_jet"}
				{view hide "proj_jet"}
				{tear "piece_missile_booster" bone "starter2"{impulse forward 25}}
				{volumes disable all}
				{spawn "starstreak_dart_carrier" "spawner1" x {impulse forward 2 com}}
				{spawn "starstreak_dart_carrier" "spawner2" x}
				{spawn "starstreak_dart_carrier" "spawner3" x {impulse forward -2 com}}
			}
			{delay 0.01 {delete}}
		}

	}
}
{("CWPS_impulse_proj" missilename(starstreak_dart) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(28) imp(55) flight_time(2.2) tail(none) eng_time(0.5))
	{on "launch_procedures"
		{with_linked_entity "missile"
			{ani_play "rotate" loop}
		}
	}
}
{("CWPS_impulse_proj" missilename(switchblade300) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(5.5) tail(none) eng_time(1))}
{("CWPS_impulse_proj" missilename(switchblade600) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(5.5) tail(none) eng_time(1))("cm_jet" dmg(750))}
{("CWPS_impulse_proj_airdropped" missilename(taurus) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(17) imp(31) flight_time(18.3) tail(proj_jet_main) eng_time(3))("cm_jet" dmg(1000))
	{on "launch_procedures"
		{delay 0.1 
			{tear "piece_small_steel" bone "part1" {impulse forward 25}}
			{tear "piece_small_steel" bone "part2" {impulse forward 25}}
		}
	}
	{on "top_attack"	
		{delay 0.9 {call "detonate"}}
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(tl4_cm) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(11) imp(18) flight_time(8.3) tail(proj_jet_atgm) eng_time(1))("cm_jet" dmg(1100))}
{("CWPS_impulse_proj" missilename(tow) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_tow) bone(tail))("cm_jet" dmg(600))}
{("CWPS_impulse_proj" missilename(tow2d) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(15) imp(25) flight_time(5) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_tow) bone(tail))("cm_jet" dmg(900))}
{("CWPS_impulse_proj" missilename(tow2e) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(15) imp(25) flight_time(5) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_tow) bone(tail))("cm_jet" dmg(900))}
{("CWPS_impulse_proj" missilename(tow2_fg) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(15) imp(25) flight_time(5) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_tow) bone(tail))}
{("CWPS_impulse_proj" missilename(tow2b) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(15) imp(25) flight_time(5.3) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_tow) bone(tail))
	{on "stuff_detonate" overload
		{if not tagged "stuff_detonate"
			{tags add "stuff_detonate"}
			{volumes disable all}
			{with_linked_entity "missile" {call "delete"}}
			{spawn "tow2b_impactor" "missile_point" x
				{impulse up 0.1 forward 25 com}
				{delay 0.01 {spawn "tow2b_core" {impulse up -40 forward 0.1 com}{volumes disable blast}}}
				{delay 0.05 {spawn "tow2b_core" {impulse up -40 forward -1.1 com}{volumes disable blast}}} 
				{delay 0.1 {stuff_detonate}}
			}
			{delay 0 {delete}}
		}
	}
}
{("CWPS_impulse_proj_eject" missilename(trigat) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.10) vel(16) imp(28) flight_time(5.5) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj" missilename(tur_kobra) rotation(1) rand_move(1) smoke_vulnerable(0) decoyprob(0.1) vel(20) imp(36) flight_time(3.8) tail(proj_jet_small) eng_time(1))("cm_jet" dmg(650))}
{("CWPS_impulse_proj" missilename(tur_kombat) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(18) imp(32) flight_time(4.5) tail(proj_jet_small) eng_time(1))("cm_jet" dmg(750))}
{("CWPS_impulse_proj" missilename(reflex) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(20) imp(36) flight_time(4.1) tail(proj_jet_small) eng_time(1))("speed_normal" coeff(1.14))("cm_jet" dmg(770))}
{("CWPS_impulse_proj" missilename(vixr) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(25) imp(45) flight_time(4) tail(proj_jet_atgm) eng_time(2))("cm_jet" dmg(1000))}
{("CWPS_impulse_proj" missilename(x_25ml_su25_ammo) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.15) vel(28) imp(51) flight_time(4.6) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj_airdropped" missilename(x31p) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(28) imp(55) flight_time(7.5) tail(proj_jet_atgm) eng_time(2))
	{on "top_attack"
		{delay 0.7 {call "detonate"}}
	}
	{on "launch_procedures"
		{delay 1.5 
			{with_linked_entity "missile"
			 {view stop "proj_jet"}
			 {view hide "proj_jet"}
			 {view start "proj_jet_main"}
			 {tear "piece_missile_booster" bone "starter"}
			 {tear "piece_small_steel" bone "part1" {impulse forward 25}}
			 {tear "piece_small_steel" bone "part2" {impulse forward 25}}
			 {tear "piece_small_steel" bone "part3" {impulse forward 25}}
			 {tear "piece_small_steel" bone "part4" {impulse forward 25}}
			}
		}		
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(x-38mte) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.15) vel(27) imp(49) flight_time(7.2) tail(proj_jet_atgm) eng_time(2))
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj_airdropped" missilename(x59m) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(16) imp(27) flight_time(15.3) tail(proj_jet_small) eng_time(3))
	{on "link_effects1"
	 {delay 0.1
	   {with_linked_entity "missile"
;		{add_view	"proj_jet_small"			"proj_jet_main"			"tail1"}
		{add_view	"proj_jet_sam"			"proj_jet"			"tail"}
		{view start "proj_tail"}
		{view start "proj_jet"}
		}
	  }
	  {ani_play "top_attack_off" 1}
	}
	{on "launch_procedures"
		{delay 0.7 {if tagged "cwps_extended_range" {with_linked_entity "missile" {ani_play "on_start"}}}}
		{delay 1.5 
		   {with_linked_entity "missile"
			{view stop "proj_jet"}
			{view hide "proj_jet"}
			{view start "proj_jet_main"}
			 {tear "piece_missile_booster" bone "part1"{impulse forward 25}}
			 {tear "piece_small_steel" bone "part2" {impulse forward 25}}
		   }
		}
	}
	{on "top_attack"
		{delay 0.7 {call "detonate"}}
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(xmim-115avt1) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(55) flight_time(4.1) tail(proj_jet_sam) eng_time(3)) }



;==========Ракеты флота
{("CWPS_impulse_proj" missilename(3m14) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.01) vel(14) imp(24) flight_time(24.5) tail(proj_jet_sam) eng_time(3))
	{on "launch_procedures"
		{delay 3 
;		      {if tagged "cwps_extended_range2"
				{with_linked_entity "missile"
					{view pause "proj_jet"}
					{view stop "proj_jet"}
					{view hide "proj_jet"}
					{tear "piece_missile_booster" bone "starter"{impulse forward 25}}
				}
;		      }
;			{if tagged "cwps_extended_range2" 
			{with_linked_entity "missile" {ani_play "on_start"}}
;			}
		}
	}
	{on "top_attack" overload
		{delay 0.6 {call "detonate"}}
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(3m54) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(14) imp(24) flight_time(18.4) tail(proj_jet_sam) eng_time(3))
     {on "detonate" overload
       {if not flag "detonate"
		{set "detonate" 1}
			{if tagged "dropped"
				{spawn "ex_air_big" "missile_point"}
			else
			{call "spawn_missile"}
			}
		{with_linked_entity "missile"
			{delete}
		}
		{delete}
       }
     }
	{on "launch_procedures"
	  {delay 5 
		{tags remove "guided"}
		{impulse fz -25}
		{tags add "dropped"}
		{with_linked_entity "missile"
			{bone cut "warhead"}
		}
		{spawn "3m54_warhead_carrier" "missile_point" x {tags add "dropped"}}
		{delay 4 {call "detonate"}}
	  }
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(3m54_warhead) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(28) imp(55) flight_time(6.4) tail(proj_jet_sam) eng_time(3))
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(basalt_p1000) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(27) imp(48) flight_time(21.7)
 tail(proj_jet_atgm) eng_time(3))
	{on "link_effects1"
	 {delay 0.1
;	  {if  not tagged "cwps_not_first_stage" 
	   {with_linked_entity "missile"
		{add_view	"proj_jet_sam"			"proj_jet"			"tail1"}
		{add_view	"proj_jet_sam"			"proj_jet"			"tail2"}
		{view start "proj_tail"}
		{view start "proj_jet"}
		}
;		}
	  }
	  {ani_play "top_attack_off" 1}
	}
	{on "launch_procedures"
		{delay 0.1 {if tagged "cwps_not_first_stage" {bone cut "addvisor_point" }}
;		{if tagged "cwps_extended_range2" 
		{with_linked_entity "missile" {ani_play "on_start" 1}}}
;		}
		{delay 4 
			{with_linked_entity "missile" 
				{view stop "proj_jet"}
				{view hide "proj_jet"}
				{view start "proj_jet_main"}
				{tear "piece_missile_booster" bone "part1"{impulse forward 25}}
				{tear "piece_missile_booster" bone "part2"{impulse forward 25}}
			}
		}
		{tags add "forced_launch"}
		{delay 0.5 {tags remove "forced_launch"}}

		{delay 1 {bone cut "addvisor_point" }}
	}
	{on "destroyed_by_kaz" overload}
}
{"basalt_p1000_impactor_link"
	 {on "missile_lock" overload
		{if rand 0.5 {inherited}}
     }
}
{("CWPS_impulse_proj" missilename(granit) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(25) imp(44) flight_time(24) tail(proj_jet_atgm) eng_time(3))
	{on "link_effects1"
		{delay 0.1
		 {if not tagged "cwps_not_first_stage" 
		   {with_linked_entity "missile"
			{add_view	"proj_jet_sam"			"proj_jet"			"tail1"}
			{view start "proj_tail"}
			{view start "proj_jet"}
			}
		  }
	  }
	  {ani_play "top_attack_off" 1}
	}
	{on "launch_procedures"
;		{delay 0.1 {if tagged "cwps_not_first_stage" {bone cut "addvisor_point" }}}
;		{delay 0.7 {if tagged "cwps_extended_range2" {with_linked_entity "missile" {tear "piece_missile_booster" bone "part2"{impulse forward 25}}}}}
		{delay 0.7 {with_linked_entity "missile" {tear "piece_missile_booster" bone "part2"{impulse forward 25}}}}
		{delay 1 {bone cut "addvisor_point" }}
		{delay 4 
		   {with_linked_entity "missile"
			{view stop "proj_jet"}
			{view hide "proj_jet"}
			{view start "proj_jet_main"}
			 {tear "piece_missile_booster" bone "starter"{impulse forward 25}}
			 {tags remove "underwater_launch"}
		   }
		}
		{tags add "forced_launch"}
		{if altitude 1 {delay 0.5 {tags remove "forced_launch"}}
		else {delay 0.6 {spawn "spherewater_big2"}}
		{delay 0.8 {tags remove "forced_launch"}}
		}
	}
	{on "destroyed_by_kaz" overload}
}
{"granit_impactor_link"
	 {on "missile_lock" overload
		{if rand 0.5 {inherited}}
     }
}
{("CWPS_impulse_proj" missilename(malahit) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(18) imp(32) flight_time(10.6) tail(proj_jet_atgm) eng_time(3))
	{on "link_effects1"
	 {delay 0.1
	   {with_linked_entity "missile"
;		{add_view	"proj_jet_atgm"			"proj_jet_main"			"tail"}
		{add_view	"proj_jet_sam"			"proj_jet"			"tail1"}
		{add_view	"proj_jet_sam"			"proj_jet"			"tail2"}
		{view start "proj_tail"}
		{view start "proj_jet"}
		}
	  }
	  {ani_play "top_attack_off" 1}
	}
	{on "launch_procedures"
		{delay 1.5 
		   {with_linked_entity "missile"
			{view stop "proj_jet"}
			{view hide "proj_jet"}
			{view start "proj_jet_main"}
			 {tear "piece_missile_booster" bone "part1"{impulse forward 25}}
			 {tear "piece_missile_booster" bone "part2"{impulse forward 25}}
		   }
		}
	}
	{on "top_attack"
		{delay 1.0 {call "detonate"}}
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(moskit) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(28) imp(53) flight_time(6.5) tail(proj_jet_sam) eng_time(3))
	{on "launch_procedures" {delay 0.1 {with_linked_entity "missile" {ani_play "on_start"}}}}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(rastrub) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(17) imp(29) flight_time(12.9)
 tail(proj_jet_atgm) eng_time(3))
	{on "link_effects1"
	 {delay 0.1
	   {with_linked_entity "missile"
		{add_view	"proj_jet_atgm"			"proj_jet"			"tail1"}
		{add_view	"proj_jet_atgm"			"proj_jet"			"tail2"}
		{add_view	"proj_jet_sam"			"proj_jet"			"tail_a"}
		{add_view	"proj_jet_sam"			"proj_jet"			"tail"}
		{view start "proj_tail"}
		{view start "proj_jet"}
		}
	  }
	  {ani_play "top_attack_off" 1}
	}
	{on "launch_procedures"
		{volumes "rangefinder" disable overlap}
		{delay 0.7 
		   {with_linked_entity "missile"
			{view stop "proj_jet"}
			{view hide "proj_jet"}
			{view start "proj_jet_main"}
			 {tear "piece_missile_booster" bone "part1"{impulse forward 10}}
			 {tear "piece_missile_booster" bone "part2"{impulse forward 10}}
		   }
		}
		{tags add "forced_launch"}
		{delay 0.7 {tags remove "forced_launch"}{volumes "rangefinder" enable overlap}}
;		{delay 1.5	{pillar_up}{physics_work 1}}


	}
	{on "top_attack" overload
	  {if not tagged "dropped"
		{tags remove "guided"}
		{tags add "dropped"}
		{impulse fz -25}
		{with_linked_entity "missile"
			{bone cut "torpedo"}
			{tear "piece_missile_booster" bone "part_cap"{impulse forward 15}}
			{tear "piece_missile_booster" bone "part_cap1"{impulse forward 8}}
		}
		{spawn "ugmt1_torpedo_impactor" "missile_point" x {tags add "dropped"} {impulse up -2 forward 30 com}}
		{delay 3 {call "detonate"}}
	  }
	}
	{on "destroyed_by_kaz" overload}

}
{("CWPS_impulse_proj" missilename(sm_2er_blockiv) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(28) imp(55) flight_time(6.6) tail(proj_jet_sam) eng_time(3))
	{on "launch_procedures"
		{delay 3 
;		      {if tagged "cwps_extended_range"
				{with_linked_entity "missile"
					{view pause "proj_jet"}
					{view stop "proj_jet"}
					{view hide "proj_jet"}
					{tear "piece_missile_booster" bone "starter"{impulse forward 25}}
				}
;		       }
		}
	}
}
{("CWPS_impulse_proj" missilename(tomahawk) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(15) imp(25) flight_time(23.5) tail(proj_jet_sam) eng_time(3))
	{on "launch_procedures"
;		{delay 3 
;				{with_linked_entity "missile"
;					{view pause "proj_jet"}
;					{view stop "proj_jet"}
;					{view hide "proj_jet"}
;					{tear "piece_missile_booster" bone "starter"{impulse forward 25}}
;				}
;			{ani_play "top_attack_off" 1} {with_linked_entity "missile" {ani_play "on_start"}}
;			{delay 15 {ani_play "top_attack_off" 1}}
;		}
	}
	{on "top_attack" overload
		{delay 1.5 {call "detonate"}}
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(asroc_vla) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0)  vel(17) imp(29) flight_time(9.2) tail(proj_jet_sam) eng_time(3))
     {on "stuff_detonate" overload
		{if tagged "dropped" {spawn "ex_air_big" "missile_point"} {delete}
		else {inherited}
		}
     }
	{on "top_attack" overload
	  {if not tagged "dropped"
		{tags remove "guided"}
		{tags add "dropped"}
		{with_linked_entity "missile"
			{bone cut "torpedo"}
			{tear "piece_missile_booster" bone "part"{impulse forward 10}}
			{tear "piece_medium_steel" bone "part1"{impulse forward 25}}
			{ani_play "brake"}
		}
		{spawn "torpedo_mk46_impactor" "missile_point" x {tags add "dropped"} {impulse up -2 forward 30 com}}
		{delay 3 {call "detonate"}}
	  }
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(veter) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(20) imp(36) flight_time(12) tail(proj_jet_sam) eng_time(5))
     {on "stuff_detonate" overload
		{if tagged "dropped" {spawn "ex_air_big" "missile_point"} {delete}
		else {inherited}
		}
     }
	{on "top_attack" overload
	  {if not tagged "dropped"
		{tags remove "guided"}
		{tags add "dropped"}
		{with_linked_entity "missile"
			{bone cut "torpedo"}
			{tear "piece_missile_booster" bone "part"{impulse forward 25}}
			{ani_play "brake"}
		}
		{spawn "ugmt1_torpedo_impactor" "missile_point" x {tags add "dropped"} {impulse up -2 forward 30 com}}
		{delay 3 {call "detonate"}}
	  }
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(vodopad) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(26) imp(46) flight_time(8) tail(proj_jet_sam) eng_time(4))
     {on "stuff_detonate" overload
		{if tagged "dropped" {spawn "ex_air_big" "missile_point"} {delete}
		else {inherited}
		}
     }
	{on "top_attack" overload
	  {if not tagged "dropped"
		{tags remove "guided"}
		{tags add "dropped"}
		{with_linked_entity "missile"
			{bone cut "torpedo"}
		}
		{spawn "ugmt1_torpedo_impactor" "missile_point" x {tags add "dropped"} {impulse up -2 forward 30 com}}
		{delay 3 {call "detonate"}}
	  }
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(ugm-84a) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(16) imp(28) flight_time(16.1) tail(proj_jet_sam) eng_time(3))
	{on "launch_procedures"
		{delay 3 
			{with_linked_entity "missile"
			 {tear "piece_missile_booster" bone "part"{impulse forward 25}}
			}
		}		
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj_airdropped" missilename(x31ad) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(28) imp(55) flight_time(7.8)
 tail(proj_jet_atgm) eng_time(3))
	{on "launch_procedures"
		{delay 1.5 
			{with_linked_entity "missile"
			 {view stop "proj_jet"}
			 {view hide "proj_jet"}
			 {view start "proj_jet_main"}
			 {tear "piece_missile_booster" bone "starter"}
			 {tear "piece_small_steel" bone "part1" {impulse forward 25}}
			 {tear "piece_small_steel" bone "part2" {impulse forward 25}}
			 {tear "piece_small_steel" bone "part3" {impulse forward 25}}
			 {tear "piece_small_steel" bone "part4" {impulse forward 25}}
			}
		}		
	}
	{on "destroyed_by_kaz" overload}
}

;torpedoes should go a little bit faster then Burke. 15-25 percents, maybe
{("CWPS_torpedo" missilename(53_65k_torpedo) rotation(0) rand_move(0) smoke_vulnerable(0) range(40) tail(proj_jet_atgm) eng_time(20))("speed_fast" coeff(0.3))}
{("CWPS_torpedo" missilename(mk48_torpedo) rotation(0) rand_move(0) smoke_vulnerable(0) range(40) tail(proj_jet_atgm) eng_time(20))("speed_fast" coeff(0.3))}
{("CWPS_torpedo" missilename(ugmt1_torpedo) rotation(0) rand_move(0) smoke_vulnerable(0) range(18) tail(proj_jet_atgm) eng_time(20))("speed_fast" coeff(0.3))}
{("CWPS_torpedo" missilename(torpedo_mk46) rotation(0) rand_move(0) smoke_vulnerable(0) range(18) tail(proj_jet_atgm) eng_time(20))("speed_fast" coeff(0.3))}
 