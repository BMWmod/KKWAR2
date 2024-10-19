(define "generic_hqcar"
    {charge 0}
    {score 1}
	{cost 1}
    {tags "%t"}
    {cw %cw}
    {cp %cp}
	{level 1}
	{fore 1}
	{dont_unfog_by_territory}
	{spawn_distance 500}
	{icon 1000}
)
(define "hqcar"
    ("generic_hqcar" c(%c) sc(%sc) t(%t %s %brig) g(%g) i(%i) b(%b) cw(%cw) cp(%cp))
    {content "* ( mp2/%s/vehicle_supporter:%n )"}
)
(define "v_hqcar"
    ("generic_v" sc(%sc) t(%t %s) s(%s) cw(%cw) cp(%cp))
    {content "%c1 ( mp2/%s/vehicle_supporter:%n ) %c2 ( %secondcrew )"}
)
(define "brigade"
	{"%name_mp_flag"           ("hqcar" c(1800) brig(%name) t(hqcar) s(%s) n(2) g(hqcar_add)   sc(1)  i(%i) cw(0) cp(-%cp)) {cost %cost}}
	{"%name_mp_flag_d"           ("hqcar" c(1800) brig(%name) t(hqcar) s(%s) n(2) g(hqcar_add)   sc(1)  i(%i) cw(0) cp(%cp)) {cost %cost}}
	{"%name_mp_flag_1" 	("generic_v" sc(1) t(%s %name) s(%s) cw(1) cp(1))  {content "%name_mp_flag ( mp2/%s/vehicle_supporter:0 ) %name_mp_flag_d ( mp2/%s/vehicle_supporter:0 )"}}
)
("brigade" s(rus) name(vvs)		i(1) cp(1000) cost(7000))
("brigade" s(rus) name(pvo)		i(2) cp(1500) cost(3700))
("brigade" s(rus) name(artbr)	i(3) cp(1000) cost(7000))
("brigade" s(rus) name(vdv)		i(4) cp(1000) cost(10000))
("brigade" s(rus) name(mot)		i(5) cp(1000) cost(10000))
("brigade" s(rus) name(specbr)	i(6) cp(1000) cost(10000))

("brigade" s(usa) name(usaf)	i(1) cp(1000) cost(7000))
("brigade" s(usa) name(usa_aa)	i(2) cp(1500) cost(3700))
("brigade" s(usa) name(usart)	i(3) cp(1000) cost(7000))
("brigade" s(usa) name(idf)		i(4) cp(1000) cost(10000))
("brigade" s(usa) name(usarmy)	i(5) cp(1000) cost(10000))
("brigade" s(usa) name(usmc)	i(6) cp(1000) cost(10000))

;под удаление после проверки, все вынесено в компактный макрос.
;{"vvs_mp_flag"           ("hqcar" c(1800) brig(vvs) t(hqcar) s(rus) n(2) g(hqcar_support)   sc(1)  i(1) cw(0) cp(-1000)) {cost 7000}}

;{"pvo_mp_flag"           ("hqcar" c(1800) brig(pvo) t(hqcar) s(rus) n(2) g(hqcar_add)   sc(1)  i(2) cw(0) cp(-150)) {cost 3700}}
;{"pvo_mp_flag_d"           ("hqcar" c(1800) brig(pvo) t(hqcar) s(rus) n(2) g(hqcar_add)   sc(1)  i(2) cw(0) cp(150)) {cost 3700}}
;{"pvo_mp_flag_1" 	("generic_v" sc(1) t(rus pvo) s(rus) cw(1) cp(1))  {content "pvo_mp_flag ( mp2/rus/vehicle_supporter:0 ) pvo_mp_flag_d ( mp2/rus/vehicle_supporter:0 )"}}

;{"artbr_mp_flag"           ("hqcar" c(1800) brig(artbr) t(hqcar) s(rus) n(0) g(hqcar_support)   sc(1)  i(3) cw(0) cp(-1000)) {cost 7000}}
;{"artbr_mp_flag_d"           ("hqcar" c(1800) brig(artbr) t(hqcar) s(rus) n(0) g(hqcar_support)   sc(1)  i(3) cw(0) cp(1000)) {cost 7000}}
;{"artbr_mp_flag_1" 	("generic_v" sc(1) t(rus artbr) s(rus) cw(1) cp(1))  {content "artbr_mp_flag ( mp2/rus/vehicle_supporter:0 ) artbr_mp_flag_d ( mp2/rus/vehicle_supporter:0 )"}}

;{"vdv_mp_flag"           ("hqcar" brig(vdv) t(hqcar) s(rus) n(2) cw(0) cp(1000)) {cost 10000}}
;{"mot_mp_flag"           ("hqcar" brig(mot) t(hqcar mot) s(rus) n(0) cw(0) cp(-1000)) {cost 10000}}
;{"mot_mp_flag_d"           ("hqcar" brig(mot) t(hqcar mot) s(rus) n(0) cw(0) cp(1000)) {cost 10000}}
;{"mot_mp_flag_1" 	("generic_v" sc(1) t(rus mot) s(rus) cw(1) cp(1))  {content "mot_mp_flag ( mp2/rus/vehicle_supporter:0 ) mot_mp_flag_d ( mp2/rus/vehicle_supporter:0 )"}}

;{"specbr_mp_flag"           ("hqcar" brig(specbr) t(hqcar specbr) s(rus) n(0) cw(0) cp(-1000)) {cost 10000}}
;{"specbr_mp_flag_d"           ("hqcar" brig(specbr) t(hqcar specbr) s(rus) n(0) cw(0) cp(1000)) {cost 10000}}
;{"specbr_mp_flag_1" 	("generic_v" sc(1) t(rus specbr) s(rus) cw(1) cp(1))  {content "specbr_mp_flag ( mp2/rus/vehicle_supporter:0 ) specbr_mp_flag_d ( mp2/rus/vehicle_supporter:0 )"}}


;{"usaf_mp_flag"           ("hqcar" c(1800) brig(usaf) t(hqcar) s(usa) n(2) g(hqcar_support)   sc(1)  i(1) cw(0) cp(-1000)) {cost 7000}}
;{"usa_aa_mp_flag"           ("hqcar" c(1800) brig(usa_aa) t(hqcar) s(usa) n(2) g(hqcar_add)   sc(1)  i(2) cw(0) cp(-150)) {cost 3700}}
;{"usa_aa_mp_flag_d"           ("hqcar" c(1800) brig(usa_aa) t(hqcar) s(usa) n(2) g(hqcar_add)   sc(1)  i(2) cw(0) cp(150)) {cost 3700}}
;{"usa_aa_mp_flag_1" 	("generic_v" sc(1) t(usa usa_aa) s(usa) cw(1) cp(1))  {content "usa_aa_mp_flag ( mp2/usa/vehicle_supporter:0 ) usa_aa_mp_flag_d ( mp2/usa/vehicle_supporter:0 )"}}

;{"usart_mp_flag"           ("hqcar" c(1800) brig(usart) t(hqcar) s(usa) n(2) g(hqcar_support)   sc(1)  i(3) cw(0) cp(-1000)) {cost 7000}}
;{"usart_mp_flag_d"           ("hqcar" c(1800) brig(usart) t(hqcar) s(usa) n(2) g(hqcar_support)   sc(1)  i(3) cw(0) cp(1000)) {cost 7000}}
;{"usart_mp_flag_1" 	("generic_v" sc(1) t(usa usart) s(usa) cw(1) cp(1))  {content "usart_mp_flag ( mp2/usa/vehicle_supporter:0 ) usart_mp_flag_d ( mp2/usa/vehicle_supporter:0 )"}}


;{"idf_mp_flag"           ("hqcar" c(1800) brig(idf) t(hqcar) s(usa) n(2) g(hqcar_support)   sc(1)  i(3) cw(0) cp(-1000)) {cost 10000}}
;{"idf_mp_flag_d"           ("hqcar" c(1800) brig(idf) t(hqcar) s(usa) n(2) g(hqcar_support)   sc(1)  i(3) cw(0) cp(1000)) {cost 10000}}
;{"idf_mp_flag_1" 	("generic_v" sc(1) t(usa idf) s(usa) cw(1) cp(1))  {content "idf_mp_flag ( mp2/usa/vehicle_supporter:0 ) idf_mp_flag_d ( mp2/usa/vehicle_supporter:0 )"}}

;{"usarmy_mp_flag"           ("hqcar" brig(usarmy) t(hqcar usarmy) s(usa) n(0) cw(0) cp(-1000)) {cost 10000}}
;{"usarmy_mp_flag_d"           ("hqcar" brig(usarmy) t(hqcar usarmy) s(usa) n(0) cw(0) cp(1000)) {cost 10000}}
;{"usarmy_mp_flag_1" 	("generic_v" sc(1) t(usa usarmy) s(usa) cw(1) cp(1))  {content "usarmy_mp_flag ( mp2/usa/vehicle_supporter:0 ) usarmy_mp_flag_d ( mp2/usa/vehicle_supporter:0 )"}}

;{"usmc_mp_flag"           ("hqcar" brig(usmc) t(hqcar) s(usa) n(0) cw(0) cp(-1000)) {cost 10000}}
;{"usmc_mp_flag_d"           ("hqcar" brig(usmc) t(hqcar) s(usa) n(0) cw(0) cp(1000)) {cost 10000}}
;{"usmc_mp_flag_1" 	("generic_v" sc(1) t(usa usmc) s(usa) cw(1) cp(1))  {content "usmc_mp_flag ( mp2/usa/vehicle_supporter:0 ) usmc_mp_flag_d ( mp2/usa/vehicle_supporter:0 )"}}

;{"nrf_mp_flag"           ("hqcar" c(1800) brig(nrf) t(hqcar) s(nato) n(2) g(hqcar_support)   sc(1)  i(1) cw(0) cp(-1000)) {cost 7000}}
;{"nato_aa_mp_flag"           ("hqcar" c(1800) brig(nato_aa) t(hqcar) s(nato) n(2) g(hqcar_add)   sc(1)  i(2) cw(0) cp(-150)) {cost 3700}}
;{"abn_mp_flag"           ("hqcar" c(1800) brig(abn) t(hqcar) s(nato) n(2) g(hqcar_support)   sc(1)  i(3) cw(0) cp(-1000)) {cost 7000}}
;{"bund_mp_flag"           ("hqcar" c(120) brig(bund) t(hqcar) s(nato) n(2) g(hqcar)   sc(1)  i(4) cw(0) cp(-1000)) {cost 10000}}
;{"gb_mp_flag"           ("hqcar" c(120) brig(gb) t(hqcar) s(nato) n(2) g(hqcar)   sc(1)  i(5) cw(0) cp(-1000)) {cost 10000}}
;{"fra_mp_flag"           ("hqcar" c(120) brig(fra) t(hqcar) s(nato) n(2) g(hqcar)   sc(1)  i(6) cw(0) cp(-1000)) {cost 10000}}

;{"cnair_mp_flag"           ("hqcar" c(1800) brig(cnair) t(hqcar) s(cn) n(2) g(hqcar_support)   sc(1)  i(1) cw(0) cp(-1000)) {cost 7000}}
;{"cnsam_mp_flag"           ("hqcar" c(1800) brig(cnsam) t(hqcar) s(cn) n(2) g(hqcar_add)   sc(1)  i(2) cw(0) cp(-150)) {cost 3700}}
;{"cnart_mp_flag"           ("hqcar" c(1800) brig(cnart) t(hqcar) s(cn) n(2) g(hqcar_support)   sc(1)  i(3) cw(0) cp(-1000)) {cost 7000}}
;{"cnheavy_mp_flag"           ("hqcar" c(120) brig(cnheavy) t(hqcar) s(cn) n(2) g(hqcar)   sc(1)  i(4) cw(0) cp(-1000)) {cost 10000}}
;{"cnmed_mp_flag"           ("hqcar" c(120) brig(cnmed) t(hqcar) s(cn) n(2) g(hqcar)   sc(1)  i(5) cw(0) cp(-1000)) {cost 10000}}
;{"iran_mp_flag"           ("hqcar" c(120) brig(iran) t(hqcar) s(cn) n(2) g(hqcar)   sc(1)  i(6) cw(0) cp(-1000)) {cost 10000}}

;{"persistent_marker_rus"           ("hqcar" c(1) brig(none) t(marker) s(rus) n(2) g(marker)   sc(1)  i(8) cw(0) cp(0)) {cost 0.1}}
;{"persistent_marker_usa"           ("hqcar" c(1) brig(none) t(marker) s(usa) n(2) g(marker)   sc(1)  i(7) cw(0) cp(0)) {cost 0.1}}
;{"persistent_marker_nato"           ("hqcar" c(1) brig(none) t(marker) s(nato) n(2) g(marker)   sc(1)  i(7) cw(0) cp(0)) {cost 0.1}}
;{"persistent_marker_cn"           ("hqcar" c(1) brig(none) t(marker) s(cn) n(2) g(marker)   sc(1)  i(7) cw(0) cp(0)) {cost 0.1}}




;------------------dummies for no-brigade mode to deal with button bug
;{"rus_dummy_flag"           ("hqcar" c(120) brig(mot) t(hqcardummy) s(rus) n(2) g(hqcardummy)   sc(1) b(hqcardummy) i(8) cw(0) cp(-1000)) {cost 10000}}
;{"usa_dummy_flag"           ("hqcar" c(120) brig(usarmy) t(hqcardummy) s(usa) n(2) g(hqcardummy)   sc(1) b(hqcardummy) i(8) cw(0) cp(-1000)) {cost 10000}}
;{"nato_dummy_flag"           ("hqcar" c(120) brig(abn) t(hqcardummy) s(nato) n(2) g(hqcardummy)   sc(1) b(hqcardummy) i(8) cw(0) cp(-1000)) {cost 10000}}
;{"chi_dummy_flag"           ("hqcar" c(120) brig(abn) t(hqcardummy) s(chi) n(2) g(hqcardummy)   sc(1) b(hqcardummy) i(8) cw(0) cp(-1000)) {cost 10000}}