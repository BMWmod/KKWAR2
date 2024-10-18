;SDL

(define "cw_blastwave_fgassist"
;макрос для затекания ударных волн в окопы
	{damage add fragments
		{energy
			%r1_2	1.2
			%r0_7	0.7
			%r0		0
		}
	}
)

(define "cw_direct_hit"
;для кораблей дописать сюда радиусы 2-3 а не 0,3
	{damage add blastwave
		{energy
			0		%energy
			0.3		%energy
			0.35	0
		}
	}
)
(define "cw_direct_hit_extended"
;для кораблей дописать сюда радиусы 2-3 а не 0,3
	{damage add blastwave
		{energy
			0		%energy
			1		%energy
			1.2		0
		}
	}
)
(define "cw_blastwave_tb_1"
	{damage add blastwave
		{energy
			0			2.5
			%end		1.2
			(+ %end 3)	0.7
			(+ %end 3.5)	0
		}
	}
)
(define "cw_blastwave_tb_2"
	{damage add blastwave
		{energy
			%apc		6.5
			%end		2.5
			(+ %end 3)	0
		}
	}
)
(define "cw_blastwave_tb_3"
	{damage add blastwave
		{energy
			%ifv		11
			%apc		6.5
			%end		2.5
			(+ %end 3)	0
		}
	}
)
(define "cw_blastwave_tb_4"
	{damage add blastwave
		{energy
			%tank		22
			%ifv		11
			%apc		6.5
			%end		2.5
			(+ %end 3)	0
		}
	}
)
(define "cw_blastwave_1_wave"
		{energy
			0				2.5
			(* %k %end)		0
		}
)
(define "cw_blastwave_2_wave"
		{energy
			(* %k %apc)		6.5
			(* %k %end)		2.5
			(+ (* %k %end) 0.1) 0
		}
)
(define "cw_blastwave_3_wave"
		{energy
			(* %k %ifv)		11
			(* %k %apc)		6.5
			(* %k %end)		2.5
			(+ (* %k %end) 0.1) 0
		}
)
(define "cw_blastwave_4_wave"
		{energy
			(* %k %tank)	22
			(* %k %ifv)		11
			(* %k %apc)		6.5
			(* %k %end)		2.5
			(+ (* %k %end) 0.1) 0
		}
)
;Пока проставим радиус поражения ударной волной как пропорциональный площади тела, т.к. основной урон от у.в. - не от самого давления,
;а от отбрасывания тела солдата на препятствие
(define "cw_blastwave"
  (define "cw_blastwave_%n"
   {damage add fragments
	{if props "human"
		{if in_fortification "trench" or in_house
			("cw_blastwave_3_wave" k(0.3) tank(%tank) ifv(%ifv) apc(%apc) end(%end))
		}
		{if cover_kind "vertical" "horizontal" "terrain"
			("cw_blastwave_%n_wave" k(0.5) tank(%tank) ifv(%ifv) apc(%apc) end(%end))
		}
		{if fsm_tags "down" ("cw_blastwave_%n_wave" k(0.7) tank(%tank) ifv(%ifv) apc(%apc) end(%end))}
		{if fsm_tags "squat"("cw_blastwave_%n_wave" k(0.85) tank(%tank) ifv(%ifv) apc(%apc) end(%end))}
		("cw_blastwave_%n_wave" k(1) tank(%tank) ifv(%ifv) apc(%apc) end(%end))
	}
	;шанс по обобщенной цели площадью 0,5м2
	{if not props "human" ("cw_blastwave_%n_wave" k(1) tank(%tank) ifv(%ifv) apc(%apc) end(%end))}
   }
   {damage add blastwave
		{if props "human"}
		{if props "cannon"("cw_blastwave_%n_wave" k(1) tank(%tank) ifv(%ifv) apc(%apc) end(%end))}
		{if props "vehicle"}
		("cw_blastwave_%n_wave" k(1) tank(%tank) ifv(%ifv) apc(%apc) end(%end))
   }
  )
)
("cw_blastwave" n(1)) ("cw_blastwave" n(2)) ("cw_blastwave" n(3)) ("cw_blastwave" n(4))

(define "chance_with_coeff"
	{chance
		0					1
		(* %k (* %chance 0.44))	1
		(* %k (* %chance 0.54))	0.7
		(* %k (* %chance 1))		0.2
		(* %k (* %chance 2))		0
	}
)
(define "common_chance"
	{if props "human"
		;площади честно померил по силуэтам, трогать их не надо
		;укрытия, кроме кустов, площадь около 0,24м2
		{if in_fortification "trench" or in_house or cover_kind "vertical" "horizontal" "terrain"
			("chance_with_coeff" k(0.69) chance(%chance))
		}
		;лежа - 0,71м2
		{if fsm_tags "down" ("chance_with_coeff" k(1.18) chance(%chance))}
		;сидя - 0,87м2
		{if fsm_tags "squat"("chance_with_coeff" k(1.32) chance(%chance))}
		;стоя - 1,04м2
		("chance_with_coeff" k(1.44) chance(%chance))
	}
	{if  props "vehicle"	;шанс по обобщенной площадью 2м2
		;нас интересует не столько сама цель, сколько попадание осколка именно в модуль, а модули не такие уж большие. Там еще коэфф. будут
		("chance_with_coeff" k(2) chance(%chance))
	}
	;шанс по обобщенной цели площадью 0,5м2
	("chance_with_coeff" k(1) chance(%chance))
)

(define "cw_fragwave"
	;Если есть броник - при попадании в броню урона с определенной вероятностью снижается на 1.2
	;Каска учитывается в расчетах площадей, но наличие не проверяется (из-за лагов) - считается,
	;что если есть броник, то есть и каска.
	{damage add fragments
		;Если есть броник - то осколок может попасть и в незащищенное место
		{if props "human" and inventory_item "armored_vest" and inventory_item "armored_helmet"
			;в укрытии 0,06м2+0,04м2
			{if in_fortification "trench" or in_house or cover_kind "vertical" "horizontal" "terrain"
				("common_chance" chance((* 0.58 %chance)))
			}
			;лежа - 0,17м2+0,06м2 сидя - 0,21м2+0,04м2 стоя - 0,24м2+0,04м2  , шанс около 30%
			("common_chance" chance((* 0.7 %chance)))
		}
		;а это если нет бронежилета или каски, либо если не человек вообще
		{energy
			%r2_5			%e2_5
			%r1_2			%e1_2
			(+ %r1_2 0.1)	0
		}
		("common_chance" chance(%chance))
	}
)
(define "cw_fragments"
	{damage add fragments
		{energy
			%r1_2	%e1_2
			%r1_0	%e1_0
			%r0_7	%e0_7
			%r0_25	%e0_25
			(+ %r0_25 0.1)	0
		}
		;Если есть броник - при попадании в броню урона не наносится.
		{if props "human" and inventory_item "armored_vest"
			;в укрытии 0,06м2+0,04м2
			{if in_fortification "trench" or in_house or cover_kind "vertical" "horizontal" "terrain"
				("common_chance" chance((* 0.58 %chance)))
			}
			;лежа - 0,17м2+0,06м2 сидя - 0,21м2+0,04м2 стоя - 0,24м2+0,04м2  , шанс около 30%
			("common_chance" chance((* 0.7 %chance)))
		}
		("common_chance" chance(%chance))
	}
)
(define "cw_contusion"
	{damage add shockwave
		{if fsm_tags "down" or in_fortification "trench" or in_house or cover_kind "vertical" "horizontal" "bush" "terrain"
			{energy
				(* %t10 0.66)	6.5 	;1.53sec/unit
				(* %t6 0.66)	4
				(* %t3 0.66)	2
				(* %t0 0.66)	0
			}
		}
		{energy
				%t10	6.5 	;1.53sec/unit
				%t6		4
				%t3		2
				%t0		0
		}
	}
)

(define "cw_seismic_1" {tag "he_07to2"} 
{damage seismic		{energy 2}	{radius 2.2}}
)
(define "cw_seismic_2" {tag "he_2to4_5"} 
	{damage seismic		{energy 5}	{radius 2.2}}
	{damage add seismic		{energy 2}	{radius 2.8}}
)
(define "cw_seismic_3" {tag "he_4_5to8"} 
	{damage seismic		{energy 10}	{radius 2.2}}
	{damage add seismic		{energy 5}	{radius 2.8}}
	{damage add seismic		{energy 2}	{radius 3.4}}
)
(define "cw_seismic_4" {tag "he_8to30"} 
	{damage seismic		{energy 15}	{radius 2.2}}
	{damage add seismic		{energy 10}	{radius 2.8}}
	{damage add seismic		{energy 5}	{radius 3.4}}
	{damage add seismic		{energy 2}	{radius 4.5}}
)
(define "cw_seismic_5" {tag "he_over30"} 
	{damage seismic		{energy 18}	{radius 2.2}}
	{damage add seismic		{energy 15}	{radius 2.8}}
	{damage add seismic		{energy 10}	{radius 3.4}}
	{damage add seismic		{energy 5}	{radius 4.5}}
	{damage add seismic		{energy 2}	{radius 5.5}}
)
(define "cw_seismic_6" {tag "he_over30"} 
	{damage seismic		{energy 22}	{radius 2.2}}
	{damage add seismic		{energy 18}	{radius 2.8}}
	{damage add seismic		{energy 15}	{radius 3.4}}
	{damage add seismic		{energy 10}	{radius 4.5}}
	{damage add seismic		{energy 5}	{radius 5.5}}
	{damage add seismic		{energy 2}	{radius 6.0}}
)
;10 ед blastwave = 1 кг ВВ + заряд. Приблизительно можно прикинуть, что масса заряда с учетом
;ТЭ пороха 0,6 примерно равна массе заряда.
;Следовательно, массу заряда для ББ снарядов надо выставлять примерно 1/3 от массы ОФС
;А для ракет (не в импакторах) - равную массе ВВ в БЧ
(define "cw_blast_mass_add"  
	{damage add blastwave
		{energy
			-1					%add
			0					0
		}
	}
)
;Powder amount should be written to AP shells because they also can detonate. Powder is weaker then TNT
(define "cw_powder_charge"  
	{damage add blastwave
		{energy
			-1					(* 3 %kg)
			0					0
		}
	}
)
;Blast charge should be written for missile's  .ammo files to make them explodable
(define "cw_blast_charge"  
	{damage add blastwave
		{energy
			-1					(* 10 %kg)
			0					0
		}
	}
)

(define "cw_heat"  {damage cumulative {damage %energy} {distance 6}})
(define "art_shell_sound"
	{sound "weapon/special/shell_fly"
		{time 3}
	}
)
(define "mortar_shell_sound"
	{sound "weapon/special/mortar_fly"
		{time 3.5}
	}
)