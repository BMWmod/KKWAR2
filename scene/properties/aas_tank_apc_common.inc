("recoil_side_volumes")
(define "accuracy_by_motion" ;  spreading depending on the speed of "body", "gun" volumes
    {AccuracyByMotion
        {MaxLinearSpeed %max_linear}               ;km/h
        {ByLinearSpeed %accuracy_by_linear}
        {MaxAngularSpeed %max_angular}             ;deg/s
        {ByAngularSpeed %accuracy_by_angular}
        {DisorderTime %disorder_time}              ;s
        {OrderTime %order_time}                    ;s
    }
)
;max_linear - максимальная линейная скорость
;accuracy_by_linear точность при этой скорости
;max_angular максимальная угловая скорость, в градусах
;accuracy_by_angular точность при этой скорости в процентах, первая тоже в процентах
;точнее 0.1 - это 10%
;disorder_time время увеличения кружка точности
;order_time - время сведения кружка точности до максимальной


;===============vision
	{extension "/properties/animation/vehicle/visor_anm.ext"}
;================================================
(define "CW_stab_2D_0_2class"
    {AccuracyByMotion
        {MaxLinearSpeed 25} {ByLinearSpeed 0.8}
        {MaxAngularSpeed 20} {ByAngularSpeed 1}
        {DisorderTime 2} {OrderTime 0} 
    }
)
(define "CW_stab_2D_0_5class"
    {AccuracyByMotion
        {MaxLinearSpeed 20} {ByLinearSpeed 0.6}
        {MaxAngularSpeed 15} {ByAngularSpeed 0.9}
        {DisorderTime 3} {OrderTime 0} 
    }
)
(define "CW_stab_2D_1_0class"
    {AccuracyByMotion
        {MaxLinearSpeed 15} {ByLinearSpeed 0.4}
        {MaxAngularSpeed 10} {ByAngularSpeed 0.8}
        {DisorderTime 3} {OrderTime 0} 
    }
)
(define "CW_stab_no_stabiliser"
    {AccuracyByMotion
        {MaxLinearSpeed 10} {ByLinearSpeed 0.2}
        {MaxAngularSpeed 10} {ByAngularSpeed 0.4}
        {DisorderTime 3} {OrderTime 0} 
    }
)
(define "CW_stab_artillery"
    {AccuracyByMotion
        {MaxLinearSpeed 15} {ByLinearSpeed 0.2}
        {MaxAngularSpeed 15} {ByAngularSpeed 0.2}
        {DisorderTime 0.2} {OrderTime 0} 
    }
)
(define "CW_stab_artillery_rt"
    {AccuracyByMotion
        {MaxLinearSpeed 15} {ByLinearSpeed 0.2}
        {MaxAngularSpeed 15} {ByAngularSpeed 0.2}
        {DisorderTime 0.2} {OrderTime (* %rechargetime (* 0.01))} 
    }
)
(define "CW_stab_otrk"
    {AccuracyByMotion
        {MaxLinearSpeed 15} {ByLinearSpeed 0.3}
        {MaxAngularSpeed 20} {ByAngularSpeed 0.3}
        {DisorderTime 1} {OrderTime 2} 
    }
)
(define "CW_stab_abm" ;В движении точность составляет abm от с места
    {AccuracyByMotion  {ByLinearSpeed %abm} {ByAngularSpeed (- 1 (*(- 1 %abm) 0.5))}}
)
(define "CW_stab_no_suo"		;нет баллистического вычислителя или нет лазерного дальномера, интегрированного в СУО
    {AccuracyByMotion  {MaxLinearSpeed 15} {MaxAngularSpeed 12} {DisorderTime 3} {OrderTime 0}}
)
(define "CW_stab_ld_suo"		;вычислитель с дальномером
    {AccuracyByMotion  {MaxLinearSpeed 25} {MaxAngularSpeed 15} {DisorderTime 4.5} {OrderTime 0}}
)
(define "CW_stab_ldwind_suo"	;СУО с лазерным дальномером  и датчиком ветра
    {AccuracyByMotion  {MaxLinearSpeed 30} {MaxAngularSpeed 20} {DisorderTime 6} {OrderTime 0}}
)
(define "CW_stab_autotrack_suo"	;СУО с лазерным дальномером  и автоматом сопровождения цели, без датчика ветра
    {AccuracyByMotion  {MaxLinearSpeed 25} {MaxAngularSpeed 30} {DisorderTime 6} {OrderTime 0}}
)
(define "CW_stab_autotrack_wind_suo"	;СУО с автоматом сопровождения цели, ЛД и датчиком ветра
    {AccuracyByMotion  {MaxLinearSpeed 30} {MaxAngularSpeed 35} {DisorderTime 6} {OrderTime 0}}
)
;================================================

{props "cwfs_fuel"}

{volume "driver_panel" {component "driver_panel"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "driver_panel1" {component "driver_panel"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "transmission" {component "transmission"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "transmission1" {component "transmission"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "autoloader" {component "autoloader"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "autoloader1" {component "autoloader"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "autoloader2" {component "autoloader"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "autoloader3" {component "autoloader"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "autoloader4" {component "autoloader"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "mgun" {component "mgun"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "mgun1" {component "mgun1"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "mgun2" {component "mgun2"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "mgun3" {component "mgun3"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "mgun4" {component "mgun4"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "mgun5" {component "mgun5"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "mgun6" {component "mgun6"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "mgun20" {component "mgun20"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "mgun21" {component "mgun21"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}

{volume "turret_ring" {component "turret_ring"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "turret_ring1" {component "turret_ring"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "panel_engine_connectors" {component "panel_engine_connectors"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "panel_engine_connectors1" {component "panel_engine_connectors"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "turret_move_engine" {component "turret_move_engine"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "turret_move_engine1" {component "turret_move_engine"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "front_wheels" {component "front_wheels"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "front_wheels1" {component "front_wheels"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "front_wheels2" {component "front_wheels"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "front_wheels3" {component "front_wheels"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "stabilizer" {component "stabilizer"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "stabilizer1" {component "stabilizer"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "stabilizer2" {component "stabilizer"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "stabilizer3" {component "stabilizer"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "gunner_panel" {component "gunner_panel"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "gunner_panel1" {component "gunner_panel"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "ppu" {component "ppu"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ppu1" {component "ppu"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ppu2" {component "ppu"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ppu3" {component "ppu"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ppu4" {component "ppu"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "apu" {component "apu"}{able clear {bullet 1}{BLAST 1}} {tags "component_internal"}}
{volume "apu1" {component "apu"}{able clear {bullet 1}{BLAST 1}} {tags "component_internal"}}

{volume "driver_place" {thickness 3} {component "driver_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "driver1_place" {thickness 3} {component "driver1_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "gunner_place" {thickness 3} {component "gunner_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "gunner1_place" {thickness 3} {component "gunner1_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "gunner2_place" {thickness 3} {component "gunner2_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "charger_place" {thickness 3} {component "charger_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "commander_place" {thickness 3} {component "commander_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "commander1_place" {thickness 3} {component "commander1_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}

{volume "seat1_place" {thickness 3} {component "seat1_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat2_place" {thickness 3} {component "seat2_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat3_place" {thickness 3} {component "seat3_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat4_place" {thickness 3} {component "seat4_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat5_place" {thickness 3} {component "seat5_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat6_place" {thickness 3} {component "seat6_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat7_place" {thickness 3} {component "seat7_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat8_place" {thickness 3} {component "seat8_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat9_place" {thickness 3} {component "seat9_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat10_place" {thickness 3} {component "seat10_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat11_place" {thickness 3} {component "seat11_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat12_place" {thickness 3} {component "seat12_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat13_place" {thickness 3} {component "seat13_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat14_place" {thickness 3} {component "seat14_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat15_place" {thickness 3} {component "seat15_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat16_place" {thickness 3} {component "seat16_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}
{volume "seat17_place" {thickness 3} {component "seat17_place"}{able clear {NoWoundDecal}{bullet 1}{BLAST 1}} {tags "crew_internal"}}

{volume "driver_triplex" {component "driver_triplex"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "driver_triplex1" {component "driver_triplex"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "driver_triplex2" {component "driver_triplex"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "commander_triplex" {component "commander_triplex"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "commander_triplex1" {component "commander_triplex"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "commander_triplex2" {component "commander_triplex"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "commander_triplex3" {component "commander_triplex"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex" {component "additional_triplex"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex_a" {component "additional_triplex"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex1" {component "additional_triplex1"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex1_a" {component "additional_triplex1"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex2" {component "additional_triplex2"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex2_a" {component "additional_triplex2"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex3" {component "additional_triplex3"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex3_a" {component "additional_triplex3"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex4" {component "additional_triplex4"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex4_a" {component "additional_triplex4"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex5" {component "additional_triplex5"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "additional_triplex5_a" {component "additional_triplex5"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}

{volume "shtora_visor" {component "shtora_visor"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "shtora_visor1" {component "shtora_visor1"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "shtora_visor2" {component "shtora_visor2"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "shtora_visor3" {component "shtora_visor3"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}

{volume "ammo_storage_main" {component "ammo_storage_main"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_main1" {component "ammo_storage_main"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_main2" {component "ammo_storage_main"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_main3" {component "ammo_storage_main"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_main4" {component "ammo_storage_main"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_main5" {component "ammo_storage_main"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "ammo_storage_autocannon" {component "ammo_storage_autocannon"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_autocannon1" {component "ammo_storage_autocannon"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_autocannon2" {component "ammo_storage_autocannon"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_autocannon3" {component "ammo_storage_autocannon"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "ammo_storage_mgun" {component "ammo_storage_mgun"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_mgun1" {component "ammo_storage_mgun"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_mgun2" {component "ammo_storage_mgun"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}
{volume "ammo_storage_mgun3" {component "ammo_storage_mgun"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}} {tags "component_internal"}}

{volume "fuel_tank_internal_a" {tags "fuel_tank_internal" "component_internal"}{component "fuel_tank_internal_a"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_internal_a1" {tags "fuel_tank_internal" "component_internal"}{component "fuel_tank_internal_a"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_internal_b" {tags "fuel_tank_internal" "component_internal"}{component "fuel_tank_internal_b"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_internal_b1" {tags "fuel_tank_internal" "component_internal"}{component "fuel_tank_internal_b"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_internal_c" {tags "fuel_tank_internal" "component_internal"}{component "fuel_tank_internal_c"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_internal_c1" {tags "fuel_tank_internal" "component_internal"}{component "fuel_tank_internal_c"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_internal_d" {tags "fuel_tank_internal" "component_internal"}{component "fuel_tank_internal_d"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_internal_d1" {tags "fuel_tank_internal" "component_internal"}{component "fuel_tank_internal_d"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}

{volume "fuel_tank_external_a" {tags "fuel_tank_external"}{component "fuel_tank_external_a"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_external_a1" {tags "fuel_tank_external"}{component "fuel_tank_external_a"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_external_b" {tags "fuel_tank_external"}{component "fuel_tank_external_b"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_external_b1" {tags "fuel_tank_external"}{component "fuel_tank_external_b"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_external_c" {tags "fuel_tank_external"}{component "fuel_tank_external_c"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_external_c1" {tags "fuel_tank_external"}{component "fuel_tank_external_c"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_external_d" {tags "fuel_tank_external"}{component "fuel_tank_external_d"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}
{volume "fuel_tank_external_d1" {tags "fuel_tank_external"}{component "fuel_tank_external_d"}{able clear {bullet 1}{BLAST 1} {NoWoundDecal}}}

;{volume "hull_integrity" {thickness 1} {component "hull_integrity"}}

(define "components_tank"
    {component "body"
        ;(mod "mp"
            {RepairTime (* %repair 100)}
        ;)
        {tags "mover" "noDestroyedView"}
    }


;====================================================
;New components


    {component "driver_panel" {RepairTime (* %repair 15)} }
    {component "transmission" {RepairTime (* %repair 25)}  }
    {component "autoloader" {RepairTime (* %repair 15)}  }
    {component "mgun" {RepairTime (* %repair 7)} }
    {component "mgun1" {RepairTime (* %repair 7)} }
    {component "mgun2" {RepairTime (* %repair 7)} }
    {component "mgun3" {RepairTime (* %repair 7)} }
    {component "mgun4" {RepairTime (* %repair 7)} }
    {component "mgun5" {RepairTime (* %repair 7)} }
    {component "mgun6" {RepairTime (* %repair 7)} }
    {component "mgun20" {RepairTime (* %repair 7)} }
    {component "mgun21" {RepairTime (* %repair 7)} }
    {component "turret_ring" {RepairTime (* %repair 25)}  }
    {component "panel_engine_connectors" {RepairTime (* %repair 20)}  }
    {component "turret_move_engine" {RepairTime (* %repair 10)}  }
    {component "front_wheels" {RepairTime (* %repair 10)}  };передние ленивцы
    {component "stabilizer" {RepairTime (* %repair 15)}  }
    {component "gunner_panel" {RepairTime (* %repair 12)}  }
    {component "ppu" {RepairTime (* %repair 5)} };основной аккумулятор. Нужен для включения двигателя
    {component "apu" {RepairTime (* %repair 7)}  };ВСУ. Нужна для работы башни при выкл. двигателе. Дает питание без двигателя.
    {component "driver_place"}
    {component "driver1_place"}
    {component "gunner_place"}
    {component "gunner1_place"}
    {component "gunner2_place"}
    {component "charger_place"}
    {component "commander_place"}
    {component "commander1_place"}
    {component "seat1_place"}
    {component "seat2_place"}
    {component "seat3_place"}
    {component "seat4_place"}
    {component "seat5_place"}
    {component "seat6_place"}
    {component "seat7_place"}
    {component "seat8_place"}
    {component "seat9_place"}
    {component "seat10_place"}
    {component "seat11_place"}
    {component "seat12_place"}
    {component "seat13_place"}
    {component "seat14_place"}
    {component "seat15_place"}
    {component "seat16_place"}
    {component "seat17_place"}

    {component "driver_triplex" {RepairTime (* %repair 5)}}	;visor bone 2
    {component "commander_triplex" {RepairTime (* %repair 15)} }	;visor bone 1
    {component "additional_triplex" {RepairTime (* %repair 10)} }	;visor bone 3
    {component "additional_triplex1" {RepairTime (* %repair 10)} }	;visor bone 4
    {component "additional_triplex2" {RepairTime (* %repair 10)} }	;visor bone 5
    {component "additional_triplex3" {RepairTime (* %repair 10)} }	;visor bone 6
    {component "additional_triplex4" {RepairTime (* %repair 10)} }	;visor bone 7
    {component "additional_triplex5" {RepairTime (* %repair 10)} }	;visor bone 8
    {component "shtora_visor" {RepairTime (* %repair 15)} }	;visor bone shtora_visor
    {component "shtora_visor1" {RepairTime (* %repair 15)} }	;visor bone shtora_visor1
    {component "shtora_visor2" {RepairTime (* %repair 15)} }	;visor bone shtora_visor2
    {component "shtora_visor3" {RepairTime (* %repair 15)} }	;visor bone shtora_visor3

    {component "ammo_storage_main" {tags "explosive"}}
    {component "ammo_storage_autocannon" {tags "explosive"}}
    {component "ammo_storage_mgun" {tags "explosive"}}

    {component "fuel_tank_internal_a" {tags "fuel_tank_internal"} {tags "explosive"}{RepairTime (* %repair 3)}}
    {component "fuel_tank_internal_b" {tags "fuel_tank_internal"} {tags "explosive"}{RepairTime (* %repair 3)}}
    {component "fuel_tank_internal_c" {tags "fuel_tank_internal"} {tags "explosive"}{RepairTime (* %repair 3)}}
    {component "fuel_tank_internal_d" {tags "fuel_tank_internal"} {tags "explosive"}{RepairTime (* %repair 3)}}
    {component "fuel_tank_external_a" {tags "fuel_tank_external"} {tags "explosive"}{RepairTime (* %repair 2)}}
    {component "fuel_tank_external_b" {tags "fuel_tank_external"} {tags "explosive"}{RepairTime (* %repair 2)}}
    {component "fuel_tank_external_c" {tags "fuel_tank_external"} {tags "explosive"}{RepairTime (* %repair 2)}}
    {component "fuel_tank_external_d" {tags "fuel_tank_external"} {tags "explosive"}{RepairTime (* %repair 2)}}


    ;{component "hull_integrity" {RepairTime (* %repair 5)}  }
	;Это - способность плавать - герметичность корпуса. Волум для нее ставится в любое место корпуса, ломается при пробитиях корпуса. 
				;Чинится (заделать пробоины). При поломке машина тонет.
    {component "gun1" {RepairTime (* %repair 10)}}
    {component "gun2" {RepairTime (* %repair 7)}}
    {component "gun3" {RepairTime (* %repair 7)}};gun2,3 - внешние контейнеры с ПТУР
	
	{component "fire_indicator"}
	{component "power_indicator"}
	{component "hweap_indicator"}
	{component "move_indicator"}
	{component "zpu_indicator"}

;end of new components
;====================================================
    {component "engine" {RepairTime (* %repair 25)}  }
    {component "turret" {RepairTime (* %repair 25)}  }
    {component "gun" {RepairTime (* %repair 15)} }
    {component "trackleft" {RepairTime (* %repair 15)} }
    {component "trackright" {RepairTime (* %repair 15)} }
)
(define "aas_armor_component"
        {setting "%volumes"
            {thickness %thickness}
            {durability{blast {koef 1} }}
            {threshold{blast {koef 1} }}
            {volumes "%volumes*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }

;			{damage_passer
;				{chance 1
;					{pierce {value 0}}
;					{blast {value 0}}
;				}
;			}
			{fragment_pass_threshold 0}	;не экранируют осколки, получают от них дамаг
        }
)
(define "aas_armor_component_custom"
        {setting "%volumes"
            {thickness %thickness}
            {durability
                {blast {value %dur_b} } {pierce {value %dur_p} }
            }
            {threshold
                {blast {value %thr_b} } {pierce {value %thr_p}  }
            }
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
			{fragment_pass_threshold 0}	;не экранируют осколки, получают от них дамаг
            {volumes "%volumes*"}
        }
)
(define "crew_places"
        {setting "crew_places"
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
            {volumes "driver_place" "driver1_place" "driver2_place" "driver3_place"
			"gunner_place" "gunner1_place" "gunner2_place" "gunner3_place" "gunner4_place"
			"charger_place" "charger1_place" "charger2_place" "charger3_place" "commander_place" "commander1_place" "commander2_place" "commander3_place"
			"seat*"
			}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
			{fragment_pass_threshold 0}	;не экранируют осколки, получают от них дамаг
        }
)
(define "headlights"
        {setting "headlights"
            {thickness 1}
            {durability{blast {koef 1} }}
            {threshold{blast {koef 1} }}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
            {volumes "lamp*"}
        }
)
(define "aas_armor_components"
		;http://btvt.info/5library/vbtt_1981_01_ujazvimost_vistrelov.htm
		;Пороги воспламенение зарядов 0-4мм, 50% - 6мм 100% - 11мм
		;взрыв зарядов 0-15мм, 50% - 18мм 100% - 20мм
		;воспламенение ВВ КС 0-9мм, 50% - 14мм 100% - 21мм
		;взрыв  ВВ КС 0-18мм, 50% - 22мм 100% - 26мм
		;частичная детонация ОФС 50% - 24мм
		;воспламенение топлива 0-14мм, 50% - 21мм 100% - 27мм
		("aas_armor_component_custom" volumes(mgun) thickness(3) dur_b(10) dur_p(5) thr_b(3) thr_p(3))
		("aas_armor_component" volumes(turret_ring) thickness(15))
		("aas_armor_component" volumes(front_wheels) thickness(15))
		("aas_armor_component" volumes(driver_panel) thickness(8))
		("aas_armor_component" volumes(transmission) thickness(8))
		("aas_armor_component" volumes(autoloader) thickness(8))
		("aas_armor_component" volumes(turret_move_engine) thickness(8))
		("aas_armor_component_custom" volumes(stabilizer) thickness(%stab) dur_b(8) dur_p(8) thr_b(8) thr_p(8))
		("aas_armor_component" volumes(gunner_panel) thickness(8))
		("aas_armor_component" volumes(apu) thickness(8))
		("aas_armor_component" volumes(ammo_storage_main) thickness(15))
		("aas_armor_component" volumes(ammo_storage_autocannon) thickness(15))
		("aas_armor_component" volumes(ammo_storage_mgun) thickness(15))
		("aas_armor_component" volumes(driver_triplex) thickness(7))
		("aas_armor_component" volumes(commander_triplex) thickness(7))
		("aas_armor_component" volumes(additional_triplex) thickness(7))
		("aas_armor_component" volumes(shtora_visor) thickness(7))
		("aas_armor_component" volumes(panel_engine_connectors) thickness(7))
		("aas_armor_component" volumes(ppu) thickness(7))
		("aas_armor_component" volumes(fuel_tank_internal) thickness(21))
		("aas_armor_component" volumes(fuel_tank_external) thickness(21))
		("aas_armor_component" volumes(other) thickness(5))
		("crew_places")
		("headlights")
)
(define "armor_engine"
    {armor
        {setting "engine"
            {thickness %t}
            {volumes "engine*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
        }
    }
)
(define "armor_tank" ; armor system details you will find at "set/interaction_entity/tank.inc"
    {armor
		("aas_armor_components" stab(%stab))
        {setting "track"
            {thickness %track_b}
            {durability {blast {value (* %track_b 4)}} {pierce {value 1000} } }
            {threshold {blast {value (* %track_b 1.5)} } }  
            {volumes "track*"}
            {whole_wound}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
        }
		{setting "wheel"
            {thickness 5}
			{durability
                {blast {value 2} } {pierce {value 2} }
            }
            {threshold
                {blast {value 2}} {pierce {value 2} }
            }
			{whole_wound}
			{volumes "wheel*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
        {setting "turret"
            {thickness %tur}
            {durability
                {blast {koef %dur} {value %dur_value} } {pierce {koef %pierce_dur} }
            }
            {threshold
                {blast {koef %thr} {value %thr_value} }
            }
            {volumes "turret" "turret1" "turret2" "turret3" "turret4" "turret5"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
			{fragment_pass_threshold 1}
        }
        {setting "gun"
            {thickness %gun}
            {durability {blast  {value (* %gun 2.1)}} {pierce {value (* %dur_value 0.5)}}}
            {threshold {blast {value (* %gun 2.0)} } {pierce {value (* %thr_value 1)} }}
            {volumes "gun*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
        }
        {setting "body"
            {thickness %bod}
            {durability
                {blast {koef %dur} {value %dur_value} } {pierce {koef %pierce_dur} }
            }
            {threshold
                {blast {koef %thr} {value %thr_value} }
            }
            {volumes "body*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
			{fragment_pass_threshold 1}

        }
        {setting "engine"
            {thickness %en}
            {durability
                {blast {koef %dur} }
            }
            {threshold
                {blast {koef %thr} }
            }
            {volumes "engine*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
        }
	}
)
(define "armor_light_btr"	;for APC - level armor - BTR, Shilka, BMD
    ;("armor_tank" t(20) track_b(7) bod(%body) tur(%turret) en(12) gun(15) stab(25) dur(1) thr(1) pierce_dur(999) dur_value(8) thr_value(7))
	("armor_tank" t(20) track_b(7) bod(%body) tur(%turret) en(12) gun(15) stab(12) dur(1) thr(1) pierce_dur(999) dur_value(8) thr_value(7))
    ("components_tank" repair(1.5))
	{sensor
		{visor "main"
			{vision "tank_main-l"}
		}
	}
)
(define "armor_btr"		;for IFV-level armor about 25mm - Bradly, BMP-1,2,3, M113.
    ;("armor_tank" t(20) track_b(10) bod(%body) tur(%turret) en(12) gun(15) stab(25) dur(1) thr(1) pierce_dur(999) dur_value(12) thr_value(10))
	("armor_tank" t(20) track_b(10) bod(%body) tur(%turret) en(12) gun(15) stab(12) dur(1) thr(1) pierce_dur(999) dur_value(20) thr_value(7))
    ("components_tank" repair(1.5))
	{sensor
		{visor "main"
			{vision "tank_main-l"}
		}
	}

)



;====================Cold War==================
(define "comp_armor_increment"
	{Volume "comp_armor_body" {tags "comp_armor"  } {able clear {NoWoundDecal}} {component "comp_armor_body"}}
	{Volume "comp_armor_body1" {tags "comp_armor"  } {able clear {NoWoundDecal}} {component "comp_armor_body"}}
	{Volume "comp_armor_body2" {tags "comp_armor"  } {able clear {NoWoundDecal}} {component "comp_armor_body"}}
	{Volume "comp_armor_turret" {tags "comp_armor"  } {able clear {NoWoundDecal}} {component "comp_armor_turret"}}
	{Volume "comp_armor_turret1" {tags "comp_armor"  } {able clear {NoWoundDecal}} {component "comp_armor_turret"}}
	{Volume "comp_armor_turret2" {tags "comp_armor"  } {able clear {NoWoundDecal}} {component "comp_armor_turret"}}
	{Volume "comp_armor_turret3" {tags "comp_armor"  } {able clear {NoWoundDecal}} {component "comp_armor_turret"}}
	{Volume "comp_armor_turret4" {tags "comp_armor"  } {able clear {NoWoundDecal}} {component "comp_armor_turret"}}
	{armor
		{setting "comp_armor_body"
			{thickness %body}
			{volumes "comp_armor_body*"}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}	
		}
		{setting "comp_armor_turret"
			{thickness %turret}
			{volumes "comp_armor_turret*"}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}	
		}
	}
)

;=========================================
(define "shield_BMP2D"
	{armor
		{setting "shield"
			{thickness 10}
			{durability {blast {value 10}} {pierce  {koef 999}}}
			{threshold {blast {value 1}}}
			{volumes "shield*"}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}	
		}
	}
)

;=========================================
(define "shield_t-64a_1981"
	{armor
		{setting "shield"
			{thickness 10}
			{durability {blast {value 20}} {pierce  {koef 999}}}
			{threshold {blast {value 10}}}
			{volumes "shield*"}
			{health_reducing
				{pierce {koef 0}}
				{blast {koef 0}}
			}	
		}
	}
)
;=========================================
(define "shield_M1"
	{volume "apploque_side1"	{Thickness 15}}
	{volume "apploque_side2"	{Thickness 15}}
	{armor
		{setting "shield"
			{thickness 35 5 5 5}
			{durability {blast {value 40}} {pierce  {koef 999}}}
			{threshold {blast {value 10}}}
			{volumes "shield*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "apploque_side"
			{thickness 15}		
			{durability {blast {value 100}} {pierce {koef 999}}}
			{threshold {blast {koef 2} {value 50}}}
			{volumes "apploque_side*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "shield_Leo2"
	{armor
		{setting "shield"
;			{thickness 7}	;указывается в дефе
			{durability {blast {value 20}} {pierce  {koef 999}}}
			{threshold {blast {value 10}}}
			{volumes "shield*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "shield_Challie2"
	{armor
		{setting "shield"
			{thickness 7}
			{durability {blast {value 20}} {pierce  {koef 999}}}
			{threshold {blast {value 10}}}
			{volumes "shield*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "shield_M1A2TUSK"
	{volume "apploque_side1"	{Thickness 15}}
	{volume "apploque_side2"	{Thickness 15}}
	{armor
		{setting "shield"
			{thickness 5}
			{durability {blast {value 40}} {pierce  {koef 999}}}
			{threshold {blast {value 10}}}
			{volumes "shield*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "apploque_side"
			{thickness 15}		
			{durability {blast {value 100}} {pierce {koef 999}}}
			{threshold {blast {koef 2} {value 50}}}
			{volumes "apploque_side*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "shield_ajax"
	{armor
		{setting "shieldl"
			{thickness 5}
			{durability {blast {value 15}} {pierce  {koef 999}}}
			{threshold {blast {value 10}}}
			{volumes "shieldl1" "shieldl2" "shieldr2"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "shieldh"
			{thickness 16}		
			{durability {blast {value 1000}} {pierce {value 1000}}}
			{threshold {blast {value 90}}{pierce {value 1000}}}
			{volumes  "shieldl3" "shieldr3" "shieldl4" "shieldr4" "shieldl5" "shieldr5" "shieldl6" "shieldr6"
			 "shieldl7" "shieldr7" "shieldl8" "shieldr8" "shieldl9" "shieldr9" "shieldl10" "shieldr10"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "ERA_element"
	{Volume "d_a%0" {tags "d_a" "d_a_1gen"  } {able clear {contact 1} {contact_ground 1} {bullet 1}{BLAST 1}} {component "d_a%0"}}
	{Volume "comp_d_a%0" {tags "1gen_ERA"  } {able clear {NoWoundDecal}} {component "d_a%0"}}
	{component "d_a%0" {tags "d_a"}}
)
(define "ERA_element_2gen"
	{Volume "d_a%0" {tags "d_a" "d_a_2gen" } {able clear {contact 1} {contact_ground 1} {bullet 1}{BLAST 1}} {component "d_a%0"}}
	{Volume "comp_d_a%0" {tags "2gen_ERA"  } {able clear {NoWoundDecal}} {component "d_a%0"}}
	{component "d_a%0" {tags "d_a"}}
)
(define "1gen_ERA"
("ERA_element" args 1)("ERA_element" args 2)("ERA_element" args 3)("ERA_element" args 4)("ERA_element" args 5)
("ERA_element" args 6)("ERA_element" args 7)("ERA_element" args 8)("ERA_element" args 9)("ERA_element" args 10)
("ERA_element" args 11)("ERA_element" args 12)("ERA_element" args 13)("ERA_element" args 14)("ERA_element" args 15)
("ERA_element" args 16)("ERA_element" args 17)("ERA_element" args 18)("ERA_element" args 19)("ERA_element" args 20)
("ERA_element" args 21)("ERA_element" args 22)("ERA_element" args 23)("ERA_element" args 24)("ERA_element" args 25)
("ERA_element" args 26)("ERA_element" args 27)("ERA_element" args 28)("ERA_element" args 29)("ERA_element" args 30)
("ERA_element" args 31)("ERA_element" args 32)("ERA_element" args 33)("ERA_element" args 34)("ERA_element" args 35)
("ERA_element" args 36)("ERA_element" args 37)("ERA_element" args 38)("ERA_element" args 39)("ERA_element" args 40)
("ERA_element" args 41)("ERA_element" args 42)("ERA_element" args 43)("ERA_element" args 44)("ERA_element" args 45)
("ERA_element" args 46)("ERA_element" args 47)("ERA_element" args 48)("ERA_element" args 49)("ERA_element" args 50)
("ERA_element" args 51)("ERA_element" args 52)("ERA_element" args 53)("ERA_element" args 54)("ERA_element" args 55)
("ERA_element" args 56)("ERA_element" args 57)("ERA_element" args 58)("ERA_element" args 59)("ERA_element" args 60)
("ERA_element" args 61)("ERA_element" args 62)("ERA_element" args 63)("ERA_element" args 64)("ERA_element" args 65)
("ERA_element" args 66)("ERA_element" args 67)("ERA_element" args 68)("ERA_element" args 69)("ERA_element" args 70)
("ERA_element" args 71)("ERA_element" args 72)("ERA_element" args 73)("ERA_element" args 74)("ERA_element" args 75)
("ERA_element" args 76)("ERA_element" args 77)("ERA_element" args 78)("ERA_element" args 79)("ERA_element" args 80)
("ERA_element" args 81)("ERA_element" args 82)("ERA_element" args 83)("ERA_element" args 84)("ERA_element" args 85)
("ERA_element" args 86)("ERA_element" args 87)("ERA_element" args 88)("ERA_element" args 89)("ERA_element" args 90)
("ERA_element" args 91)("ERA_element" args 92)("ERA_element" args 93)("ERA_element" args 94)("ERA_element" args 95)
("ERA_element" args 96)("ERA_element" args 97)("ERA_element" args 98)("ERA_element" args 99)
)
(define "1gen_ERA_100-130"	;dont use 130d_a together with NERA, or basic d_a with extended NERA - component limit (in MP only)
("ERA_element" args 100)
("ERA_element" args 101)("ERA_element" args 102)("ERA_element" args 103)("ERA_element" args 104)("ERA_element" args 105)
("ERA_element" args 106)("ERA_element" args 107)("ERA_element" args 108)("ERA_element" args 109)("ERA_element" args 110)
("ERA_element" args 111)("ERA_element" args 112)("ERA_element" args 113)("ERA_element" args 114)("ERA_element" args 115)
("ERA_element" args 116)("ERA_element" args 117)("ERA_element" args 118)("ERA_element" args 119)("ERA_element" args 120)
("ERA_element" args 121)("ERA_element" args 122)("ERA_element" args 123)("ERA_element" args 124)("ERA_element" args 125)
("ERA_element" args 126)("ERA_element" args 127)("ERA_element" args 128)("ERA_element" args 129)("ERA_element" args 130)
)
(define "2gen_ERA"
("ERA_element_2gen" args 1)("ERA_element_2gen" args 2)("ERA_element_2gen" args 3)("ERA_element_2gen" args 4)("ERA_element_2gen" args 5)
("ERA_element_2gen" args 6)("ERA_element_2gen" args 7)("ERA_element_2gen" args 8)("ERA_element_2gen" args 9)("ERA_element_2gen" args 10)
("ERA_element_2gen" args 11)("ERA_element_2gen" args 12)("ERA_element_2gen" args 13)("ERA_element_2gen" args 14)("ERA_element_2gen" args 15)
("ERA_element_2gen" args 16)("ERA_element_2gen" args 17)("ERA_element_2gen" args 18)("ERA_element_2gen" args 19)("ERA_element_2gen" args 20)
("ERA_element_2gen" args 21)("ERA_element_2gen" args 22)("ERA_element_2gen" args 23)("ERA_element_2gen" args 24)("ERA_element_2gen" args 25)
("ERA_element_2gen" args 26)("ERA_element_2gen" args 27)("ERA_element_2gen" args 28)("ERA_element_2gen" args 29)("ERA_element_2gen" args 30)
("ERA_element_2gen" args 31)("ERA_element_2gen" args 32)("ERA_element_2gen" args 33)("ERA_element_2gen" args 34)("ERA_element_2gen" args 35)
("ERA_element_2gen" args 36)("ERA_element_2gen" args 37)("ERA_element_2gen" args 38)("ERA_element_2gen" args 39)("ERA_element_2gen" args 40)
("ERA_element_2gen" args 41)("ERA_element_2gen" args 42)("ERA_element_2gen" args 43)("ERA_element_2gen" args 44)("ERA_element_2gen" args 45)
("ERA_element_2gen" args 46)("ERA_element_2gen" args 47)("ERA_element_2gen" args 48)("ERA_element_2gen" args 49)("ERA_element_2gen" args 50)
("ERA_element_2gen" args 51)("ERA_element_2gen" args 52)("ERA_element_2gen" args 53)("ERA_element_2gen" args 54)("ERA_element_2gen" args 55)
("ERA_element_2gen" args 56)("ERA_element_2gen" args 57)("ERA_element_2gen" args 58)("ERA_element_2gen" args 59)("ERA_element_2gen" args 60)
("ERA_element_2gen" args 61)("ERA_element_2gen" args 62)("ERA_element_2gen" args 63)("ERA_element_2gen" args 64)("ERA_element_2gen" args 65)
("ERA_element_2gen" args 66)("ERA_element_2gen" args 67)("ERA_element_2gen" args 68)("ERA_element_2gen" args 69)("ERA_element_2gen" args 70)
("ERA_element_2gen" args 71)("ERA_element_2gen" args 72)("ERA_element_2gen" args 73)("ERA_element_2gen" args 74)("ERA_element_2gen" args 75)
("ERA_element_2gen" args 76)("ERA_element_2gen" args 77)("ERA_element_2gen" args 78)("ERA_element_2gen" args 79)("ERA_element_2gen" args 80)
("ERA_element_2gen" args 81)("ERA_element_2gen" args 82)("ERA_element_2gen" args 83)("ERA_element_2gen" args 84)("ERA_element_2gen" args 85)
("ERA_element_2gen" args 86)("ERA_element_2gen" args 87)("ERA_element_2gen" args 88)("ERA_element_2gen" args 89)("ERA_element_2gen" args 90)
("ERA_element_2gen" args 91)("ERA_element_2gen" args 92)("ERA_element_2gen" args 93)("ERA_element_2gen" args 94)("ERA_element_2gen" args 95)
("ERA_element_2gen" args 96)("ERA_element_2gen" args 97)("ERA_element_2gen" args 98)("ERA_element_2gen" args 99)
)
(define "2gen_ERA_100-130"
("ERA_element_2gen" args 100)
("ERA_element_2gen" args 101)("ERA_element_2gen" args 102)("ERA_element_2gen" args 103)("ERA_element_2gen" args 104)("ERA_element_2gen" args 105)
("ERA_element_2gen" args 106)("ERA_element_2gen" args 107)("ERA_element_2gen" args 108)("ERA_element_2gen" args 109)("ERA_element_2gen" args 110)
("ERA_element_2gen" args 111)("ERA_element_2gen" args 112)("ERA_element_2gen" args 113)("ERA_element_2gen" args 114)("ERA_element_2gen" args 115)
("ERA_element_2gen" args 116)("ERA_element_2gen" args 117)("ERA_element_2gen" args 118)("ERA_element_2gen" args 119)("ERA_element_2gen" args 120)
("ERA_element_2gen" args 121)("ERA_element_2gen" args 122)("ERA_element_2gen" args 123)("ERA_element_2gen" args 124)("ERA_element_2gen" args 125)
("ERA_element_2gen" args 126)("ERA_element_2gen" args 127)("ERA_element_2gen" args 128)("ERA_element_2gen" args 129)("ERA_element_2gen" args 130)
)
(define "d_a_Kontakt1"
	("1gen_ERA")	;320mm
	{armor
		{setting "d_a"
			{thickness 10}
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 50}
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "d_a_ERAWA"
	("1gen_ERA")	;360mm
	{armor
		{setting "d_a"
			{thickness 11}
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 56}
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
(define "d_a_dyna72"
	("2gen_ERA")	;Противотандемная ДЗ
	;120/500 на корпусе под 68, около 190/800 на башне под 0 (волумы вертикальны)
	{armor
		{setting "d_a_hull"
			{thickness 33}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a1" "d_a2" "d_a3" "d_a4" "d_a5" "d_a6" "d_a7" "d_a8" "d_a9" "d_a10"
			"d_a11" "d_a12" "d_a13" "d_a14" "d_a15" "d_a16" "d_a17" "d_a18" "d_a19" "d_a20"
			 "d_a23" "d_a24" "d_a25" "d_a26" "d_a27" "d_a28" }
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_hull"
			{thickness 61}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a1" "comp_d_a2" "comp_d_a3" "comp_d_a4" "comp_d_a5" "comp_d_a6" "comp_d_a7" "comp_d_a8" "comp_d_a9" "comp_d_a10"
			"comp_d_a11" "comp_d_a12" "comp_d_a13" "comp_d_a14" "comp_d_a15" "comp_d_a16" "comp_d_a17" "comp_d_a18" "comp_d_a19" "comp_d_a20"
			 "comp_d_a23" "comp_d_a24" "comp_d_a25" "comp_d_a26" "comp_d_a27" "comp_d_a28" }
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		
		{setting "d_a_turret"
			{thickness 95}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a21" "d_a22""d_a29" "d_a30"
			"d_a31" "d_a32" "d_a33" "d_a34" "d_a35" "d_a36" "d_a37" "d_a38"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_turret"
			{thickness 305}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a21" "comp_d_a22" "comp_d_a29" "comp_d_a30"
			"comp_d_a31" "comp_d_a32" "comp_d_a33" "comp_d_a34" "comp_d_a35" "comp_d_a36" "comp_d_a37" "comp_d_a38"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "d_a"
			{thickness 10}
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_front"	;60 град
			{thickness 75}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 0.15} {calibre 6}}}
			{volumes  "comp_d_a31" "comp_d_a32" "comp_d_a33" "comp_d_a34" "comp_d_a35" "comp_d_a36" "comp_d_a37" "comp_d_a38" "comp_d_a39" "comp_d_a40"
			"comp_d_a41" "comp_d_a42" "comp_d_a43" "comp_d_a44" "comp_d_a45" "comp_d_a46" "comp_d_a47" "comp_d_a48" "comp_d_a49" "comp_d_a40"
			"comp_d_a51" "comp_d_a52" "comp_d_a53" }
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_side"		;0 град
			{thickness 180}		;Причины неясны, должно-то быть около 240
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 0.15} {calibre 6}}}
			{volumes "comp_d_a1" "comp_d_a2" "comp_d_a3" "comp_d_a4" "comp_d_a5" "comp_d_a6" "comp_d_a7" "comp_d_a8" "comp_d_a9" "comp_d_a10"
			"comp_d_a11" "comp_d_a12" "comp_d_a13" "comp_d_a14" "comp_d_a15" "comp_d_a16" "comp_d_a17" "comp_d_a18" "comp_d_a19" "comp_d_a20"
			"comp_d_a21" "comp_d_a22" "comp_d_a23" "comp_d_a24" "comp_d_a25" "comp_d_a26" "comp_d_a27" "comp_d_a28" "comp_d_a29" "comp_d_a30"
			"comp_d_a54" "comp_d_a55" "comp_d_a56" "comp_d_a57" "comp_d_a58" "comp_d_a59" "comp_d_a50"
			"comp_d_a61" "comp_d_a62" "comp_d_a63" "comp_d_a64" "comp_d_a65" "comp_d_a66" "comp_d_a67" "comp_d_a68" "comp_d_a69" "comp_d_a60"
			"comp_d_a71" "comp_d_a72" "comp_d_a73" "comp_d_a74" "comp_d_a75" "comp_d_a76" "comp_d_a77" "comp_d_a78" "comp_d_a79" "comp_d_a70"
			"comp_d_a81" "comp_d_a82" "comp_d_a83" "comp_d_a84" "comp_d_a85" "comp_d_a86" "comp_d_a87"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "d_a_ARAT1"
	("1gen_ERA")	;держит 500 в борт по нормали (с броней), источник не помню, но фактически там установлено елочкой, под внутренним наклоном.
	{armor
		{setting "d_a"
			{thickness 10}
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 180}			
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
(define "d_a_BRAT"
	("1gen_ERA")	;Стойкость неизвестна, м. б. родственна ARAT
	{armor
		{setting "d_a"
			{thickness 10}
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_front"	;60 град
			{thickness 75}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 0.15} {calibre 6}}}
			{volumes  "comp_d_a31" "comp_d_a32" "comp_d_a33" "comp_d_a34" "comp_d_a35" "comp_d_a36" "comp_d_a37" "comp_d_a38" "comp_d_a39" "comp_d_a40"
			"comp_d_a41" "comp_d_a42" "comp_d_a43" "comp_d_a44" "comp_d_a45" "comp_d_a46" "comp_d_a47" "comp_d_a48" "comp_d_a49" "comp_d_a50"
			"comp_d_a51" "comp_d_a52" "comp_d_a53" }
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_side"		;0 град
			{thickness 180}		;Причины неясны, должно-то быть около 240
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 0.15} {calibre 6}}}
			{volumes "comp_d_a1" "comp_d_a2" "comp_d_a3" "comp_d_a4" "comp_d_a5" "comp_d_a6" "comp_d_a7" "comp_d_a8" "comp_d_a9" "comp_d_a10"
			"comp_d_a11" "comp_d_a12" "comp_d_a13" "comp_d_a14" "comp_d_a15" "comp_d_a16" "comp_d_a17" "comp_d_a18" "comp_d_a19" "comp_d_a20"
			"comp_d_a21" "comp_d_a22" "comp_d_a23" "comp_d_a24" "comp_d_a25" "comp_d_a26" "comp_d_a27" "comp_d_a28" "comp_d_a29" "comp_d_a30"
			"comp_d_a54" "comp_d_a55" "comp_d_a56" "comp_d_a57" "comp_d_a58" "comp_d_a59" "comp_d_a50"
			"comp_d_a61" "comp_d_a62" "comp_d_a63" "comp_d_a64" "comp_d_a65" "comp_d_a66" "comp_d_a67" "comp_d_a68" "comp_d_a69" "comp_d_a60"
			"comp_d_a71" "comp_d_a72" "comp_d_a73" "comp_d_a74" "comp_d_a75" "comp_d_a76" "comp_d_a77" "comp_d_a78" "comp_d_a79" "comp_d_a70"
			"comp_d_a81" "comp_d_a82" "comp_d_a83" "comp_d_a84" "comp_d_a85" "comp_d_a86" "comp_d_a87"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
(define "d_a_WRAP2"
	("1gen_ERA")	;Стойкость неизвестна, м. б. родственна ARAT, представляет собой BRAT в других кожухах
					;Т. е. 500мм, если ДЗ стоит под 45 град.
	{armor
		{setting "d_a"
			{thickness 10}
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"	;45 гр
			{thickness 166}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 0.15} {calibre 6}}}
			{volumes  "comp_d_a*" }
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
(define "d_a_CLARA"
	("1gen_ERA")	;держит примерно 330мм
	{armor
		{setting "d_a"
			{thickness 20}
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 145}			
			{durability {blast {koef 12}} {pierce {value 16}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "d_a_kaktus_bmp3"
	("1gen_ERA")	;прирост защиты от БС невелик, защищает от 23мм в борт, 30мм в 30 гр, стойкость около 20мм, но от КС держит 500
	{armor
		{setting "d_a_turret"	;предп. 60 град
			{thickness 10}
			{durability {blast {koef 12}} {pierce {value 20}}}
			{threshold {blast {koef 1}} {pierce {koef 2} {calibre 6}}}
			{volumes "d_a47" "d_a48" "d_a49" "d_a50" "d_a51" "d_a52" "d_a53" "d_a54" "d_a55" "d_a56"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "d_a_front"	;30 град
			{thickness 10}
			{durability {blast {koef 12}} {pierce {value 20}}}
			{threshold {blast {koef 1}} {pierce {koef 2} {calibre 6}}}
			{volumes "d_a37" "d_a38" "d_a39" "d_a40" "d_a41" "d_a42" "d_a43" "d_a44" "d_a45" "d_a46"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "d_a_side"		;0 град
			{thickness 10}
			{durability {blast {koef 12}} {pierce {value 20}}}
			{threshold {blast {koef 1}} {pierce {koef 2} {calibre 6}}}
			{volumes "d_a1" "d_a2" "d_a3" "d_a4" "d_a5" "d_a6" "d_a7" "d_a8" "d_a9" "d_a10" "d_a11" "d_a12" "d_a13" "d_a14" "d_a15" "d_a16" "d_a17" "d_a18" "d_a19"
			"d_a20" "d_a21" "d_a22" "d_a23" "d_a24" "d_a25" "d_a26" "d_a27" "d_a28" "d_a29" "d_a30" "d_a31" "d_a32" "d_a33" "d_a34" "d_a35" "d_a36"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_turret"	;предп. 60 град
			{thickness 120}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 0.15} {calibre 6}}}
			{volumes "comp_d_a47" "comp_d_a48" "comp_d_a49" "comp_d_a50" "comp_d_a51" "comp_d_a52" "comp_d_a53" "comp_d_a54" "comp_d_a55" "comp_d_a56"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_front"	;35 град
			{thickness 200}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 0.15} {calibre 6}}}
			{volumes "comp_d_a37" "comp_d_a38" "comp_d_a39" "comp_d_a40" "comp_d_a41" "comp_d_a42" "comp_d_a43" "comp_d_a44" "comp_d_a45" "comp_d_a46"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_side"		;0 град
			{thickness 190}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 0.15} {calibre 6}}}
			{volumes "comp_d_a1" "comp_d_a2" "comp_d_a3" "comp_d_a4" "comp_d_a5" "comp_d_a6" "comp_d_a7" "comp_d_a8" "comp_d_a9" "comp_d_a10"
			"comp_d_a11" "comp_d_a12" "comp_d_a13" "comp_d_a14" "comp_d_a15" "comp_d_a16" "comp_d_a17" "comp_d_a18" "comp_d_a19" "comp_d_a20"
			"comp_d_a21" "comp_d_a22" "comp_d_a23" "comp_d_a24" "comp_d_a25" "comp_d_a26" "comp_d_a27" "comp_d_a28" "comp_d_a29" "comp_d_a30"
			"comp_d_a31" "comp_d_a32" "comp_d_a33" "comp_d_a34" "comp_d_a35" "comp_d_a36"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "d_a_Kontakt5"
	("1gen_ERA")	;200 - 500, perhaps, from old NIIstali site
					
	{armor
		{setting "d_a"
			{thickness 74}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 15}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "d_a_FY4"
	("2gen_ERA")	;180 - 500 approx, antitandem
					
	{armor
		{setting "d_a"
			{thickness 34}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 60}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
(define "d_a_FY5"
	("2gen_ERA")	;250 - 600, antitandem
					
	{armor
		{setting "d_a"
			{thickness 47}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 66}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================

(define "d_a_Relict_bmpt"
	("2gen_ERA")	
					
	{armor
		{setting "d_a"
			{thickness 110}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 15}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)

(define "d_a_Relict"
	("2gen_ERA")	
					
	{armor
		{setting "d_a"
			{thickness 90}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 15}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)

(define "d_a_Relict_t72b3"
	("2gen_ERA")	
					
	{armor
		{setting "d_a_normal"
			{thickness 100}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a1" "d_a2" "d_a3" "d_a4" "d_a5" "d_a7" "d_a9" "d_a10" 
			"d_a11" "d_a12" "d_a13" "d_a14" "d_a15" "d_a16" "d_a17" "d_a18" 
			"d_a19" "d_a20" "d_a21" "d_a22" "d_a23" "d_a24" "d_a25" "d_a26" "d_a27" "d_a28" 
			"d_a29" "d_a30" "d_a31" "d_a32" "d_a33" "d_a34" "d_a35" "d_a36" "d_a37" "d_a38" 
			"d_a45" "d_a46" "d_a47" "d_a48" 
			"d_a49" "d_a50" "d_a51" "d_a52" "d_a53" "d_a54" "d_a55" "d_a56" "d_a57" "d_a58" 
			"d_a59" "d_a60" "d_a61" "d_a62" "d_a63" "d_a64" "d_a65" "d_a66" "d_a67" "d_a68" 
			"d_a69" "d_a70" "d_a71"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_normal"
			{thickness 15}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a1" "comp_d_a2" "comp_d_a3" "comp_d_a4" "comp_d_a5" "comp_d_a7" "comp_d_a9" "comp_d_a10" 
			"comp_d_a11" "comp_d_a12" "comp_d_a13" "comp_d_a14" "comp_d_a15" "comp_d_a16" "comp_d_a17" "comp_d_a18" 
			"comp_d_a19" "comp_d_a20" "comp_d_a21" "comp_d_a22" "comp_d_a23" "comp_d_a24" "comp_d_a25" "comp_d_a26" "comp_d_a27" "comp_d_a28" 
			"comp_d_a29" "comp_d_a30" "comp_d_a31" "comp_d_a32" "comp_d_a33" "comp_d_a34" "comp_d_a35" "comp_d_a36" "comp_d_a37" "comp_d_a38" 
			"comp_d_a45" "comp_d_a46" "comp_d_a47" "comp_d_a48" 
			"comp_d_a49" "comp_d_a50" "comp_d_a51" "comp_d_a52" "comp_d_a53" "comp_d_a54" "comp_d_a55" "comp_d_a56" "comp_d_a57" "comp_d_a58" 
			"comp_d_a59" "comp_d_a60" "comp_d_a61" "comp_d_a62" "comp_d_a63" "comp_d_a64" "comp_d_a65" "comp_d_a66" "comp_d_a67" "comp_d_a68" 
			"comp_d_a69" "comp_d_a70" "comp_d_a71"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		
		{setting "d_a_side"	
			{thickness 200}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a6" "d_a8" "d_a39" "d_a40" "d_a41" "d_a42" "d_a43" "d_a44"
			"d_a72" "d_a73" "d_a74" "d_a75" "d_a76" "d_a77" "d_a78" "d_a79" "d_a80"
			"d_a81" "d_a82" "d_a83" "d_a84" "d_a85" "d_a86" "d_a87" "d_a88" "d_a89" "d_a90" 
			"d_a91" "d_a92" "d_a93" "d_a94" "d_a95" "d_a96"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_side" 
			{thickness 30}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a6" "comp_d_a8" "comp_d_a39" "comp_d_a40" "comp_d_a41" "comp_d_a42" "comp_d_a43" "comp_d_a44"
			"comp_d_a72" "comp_d_a73" "comp_d_a74" "comp_d_a75" "comp_d_a76" "comp_d_a77" "comp_d_a78" "comp_d_a79" "comp_d_a80"
			"comp_d_a81" "comp_d_a82" "comp_d_a83" "comp_d_a84" "comp_d_a85" "comp_d_a86" "comp_d_a87" "comp_d_a88" "comp_d_a89" "comp_d_a90" 
			"comp_d_a91" "comp_d_a92" "comp_d_a93" "comp_d_a94" "comp_d_a95" "comp_d_a96"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}		
	}
)

(define "d_a_Malakhit"
	("2gen_ERA")	
			
	{armor
		{setting "d_a_normal"
			{thickness 110}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a1" "d_a2" "d_a3" "d_a4" "d_a5" "d_a6" "d_a7" "d_a8" "d_a9" "d_a10" "d_a11" "d_a12" "d_a13" "d_a14" "d_a15" "d_a16" "d_a17" "d_a18" "d_a19"
			"d_a20" "d_a21" "d_a22" "d_a23" "d_a24" "d_a25" "d_a26" "d_a27" "d_a28" "d_a29" "d_a30" "d_a31" "d_a32" "d_a33" "d_a34" "d_a35" "d_a36"
			"d_a37" "d_a38" "d_a39" "d_a40" "d_a41" "d_a42" "d_a43" "d_a44" "d_a45"	"d_a66" "d_a67" "d_a68" "d_a69"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_normal"
			{thickness 15}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a1" "comp_d_a2" "comp_d_a3" "comp_d_a4" "comp_d_a5" "comp_d_a6" "comp_d_a7" "comp_d_a8" "comp_d_a9" "comp_d_a10" "comp_d_a11" "comp_d_a12" "comp_d_a13" "comp_d_a14" "comp_d_a15" "comp_d_a16" "comp_d_a17" "comp_d_a18" "comp_d_a19"
			"comp_d_a20" "comp_d_a21" "comp_d_a22" "comp_d_a23" "comp_d_a24" "comp_d_a25" "comp_d_a26" "comp_d_a27" "comp_d_a28" "comp_d_a29" "comp_d_a30" "comp_d_a31" "comp_d_a32" "comp_d_a33" "comp_d_a34" "comp_d_a35" "comp_d_a36"
			"comp_d_a37" "comp_d_a38" "comp_d_a39" "comp_d_a40" "comp_d_a41" "comp_d_a42" "comp_d_a43" "comp_d_a44" "comp_d_a45"	"comp_d_a66" "comp_d_a67" "comp_d_a68" "comp_d_a69"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		
		{setting "d_a_side"	
			{thickness 94}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a46" "d_a47" "d_a48" "d_a49" "d_a50" "d_a51" "d_a52" "d_a53" "d_a54" "d_a55" 
			"d_a56" "d_a57" "d_a58" "d_a59" "d_a60" "d_a61" "d_a62" "d_a63" "d_a64" "d_a65"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_side" 
			{thickness 45}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a46" "comp_d_a47" "comp_d_a48" "comp_d_a49" "comp_d_a50" "comp_d_a51" "comp_d_a52" "comp_d_a53" "comp_d_a54" "comp_d_a55" 
			"comp_d_a56" "comp_d_a57" "comp_d_a58" "comp_d_a59" "comp_d_a60" "comp_d_a61" "comp_d_a62" "comp_d_a63" "comp_d_a64" "comp_d_a65"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
(define "d_a_Malakhit_t15"
	("2gen_ERA")	
	;the only difference fron T-14 is what modules have angled ERA (side) and what have flat (top, front)
	{armor
		{setting "d_a_normal"
			{thickness 110}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a1" "d_a2" "d_a3" "d_a4" "d_a5" "d_a6" "d_a7" "d_a8" "d_a9" "d_a10" "d_a11" "d_a12" "d_a13" "d_a14" "d_a15" "d_a16" "d_a17" "d_a18" "d_a19"
			"d_a20" "d_a21" "d_a22" "d_a23" "d_a24" "d_a25" "d_a26" "d_a27" "d_a28" "d_a49" "d_a50" "d_a51" "d_a52" "d_a53"  "d_a73" "d_a74" "d_a75" "d_a76" "d_a77" "d_a78" "d_a79" "d_a80"
			}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_normal"
			{thickness 15}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a1" "comp_d_a2" "comp_d_a3" "comp_d_a4" "comp_d_a5" "comp_d_a6" "comp_d_a7" "comp_d_a8" "comp_d_a9" "comp_d_a10" "comp_d_a11" "comp_d_a12" "comp_d_a13" "comp_d_a14" "comp_d_a15" "comp_d_a16" "comp_d_a17" "comp_d_a18" "comp_d_a19"
			"comp_d_a20" "comp_d_a21" "comp_d_a22" "comp_d_a23" "comp_d_a24" "comp_d_a25" "comp_d_a26" "comp_d_a27" "comp_d_a28" "comp_d_a29" "comp_d_a49" "comp_d_a50" "comp_d_a51" "comp_d_a52" "comp_d_a53" "comp_d_a73" "comp_d_a74" "comp_d_a75" "comp_d_a76" "comp_d_a77" "comp_d_a78" "comp_d_a79" "comp_d_a80"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		
		{setting "d_a_side"	
			{thickness 94}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a30" "d_a31" "d_a32" "d_a33" "d_a34" "d_a35" "d_a36" "d_a37" "d_a38" "d_a39" "d_a40" "d_a41" "d_a42" "d_a43" "d_a44" "d_a45" "d_a46" "d_a47" "d_a48" "d_a54" "d_a55" "d_a56" "d_a57" "d_a58" "d_a59" "d_a60" "d_a61" "d_a62" "d_a63" "d_a64" "d_a65" "d_a66" "d_a67" "d_a68" "d_a69" "d_a70" "d_a71" "d_a72"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_side" 
			{thickness 45}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a30" "comp_d_a31" "comp_d_a32" "comp_d_a33" "comp_d_a34" "comp_d_a35" "comp_d_a36"
			"comp_d_a37" "comp_d_a38" "comp_d_a39" "comp_d_a40" "comp_d_a41" "comp_d_a42" "comp_d_a43" "comp_d_a44" "comp_d_a45"  "comp_d_a46"  "comp_d_a47"  "comp_d_a48" "comp_d_a54" "comp_d_a55" 
			"comp_d_a56" "comp_d_a57" "comp_d_a58" "comp_d_a59" "comp_d_a60" "comp_d_a61" "comp_d_a62" "comp_d_a63" "comp_d_a64" "comp_d_a65" "comp_d_a66" "comp_d_a67" "comp_d_a68" "comp_d_a69" "comp_d_a70" "comp_d_a71" "comp_d_a72"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
(define "d_a_noz"
	("1gen_ERA")	
	{armor
		{setting "d_a"
			{thickness 45}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 35}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)

(define "d_a_Duplet"
	
("ERA_element" args 1)("ERA_element" args 2)("ERA_element" args 3)("ERA_element" args 4)("ERA_element" args 5)
("ERA_element" args 6)("ERA_element" args 7)("ERA_element" args 8)("ERA_element_2gen" args 9)("ERA_element_2gen" args 10)
("ERA_element" args 11)("ERA_element" args 12)("ERA_element" args 13)("ERA_element" args 14)("ERA_element" args 15)
("ERA_element" args 16)("ERA_element" args 17)("ERA_element_2gen" args 18)("ERA_element_2gen" args 19)("ERA_element_2gen" args 20)
("ERA_element" args 21)("ERA_element" args 22)("ERA_element" args 23)("ERA_element" args 24)("ERA_element" args 25)
("ERA_element" args 26)("ERA_element" args 27)("ERA_element" args 28)("ERA_element" args 29)("ERA_element" args 30)
("ERA_element" args 31)("ERA_element" args 32)("ERA_element_2gen" args 33)("ERA_element_2gen" args 34)("ERA_element_2gen" args 35)
("ERA_element_2gen" args 36)("ERA_element" args 37)("ERA_element" args 38)("ERA_element_2gen" args 39)("ERA_element_2gen" args 40)
("ERA_element_2gen" args 41)("ERA_element_2gen" args 42)("ERA_element_2gen" args 43)("ERA_element_2gen" args 44)("ERA_element_2gen" args 45)
("ERA_element_2gen" args 46)("ERA_element_2gen" args 47)("ERA_element_2gen" args 48)("ERA_element_2gen" args 49)("ERA_element_2gen" args 50)
("ERA_element_2gen" args 51)("ERA_element_2gen" args 52)("ERA_element_2gen" args 53)("ERA_element_2gen" args 54)("ERA_element" args 55)
("ERA_element" args 56)("ERA_element" args 57)("ERA_element" args 58)("ERA_element_2gen" args 59)("ERA_element_2gen" args 60)
("ERA_element_2gen" args 61)("ERA_element_2gen" args 62)("ERA_element" args 63)("ERA_element" args 64)("ERA_element" args 65)
("ERA_element" args 66)("ERA_element" args 67)("ERA_element" args 68)("ERA_element" args 69)("ERA_element" args 70)
("ERA_element_2gen" args 71)("ERA_element_2gen" args 72)("ERA_element_2gen" args 73)("ERA_element_2gen" args 74)("ERA_element_2gen" args 75)
("ERA_element_2gen" args 76)("ERA_element_2gen" args 77)("ERA_element" args 78)("ERA_element" args 79)("ERA_element" args 80)
("ERA_element" args 81)("ERA_element" args 82)("ERA_element" args 83)("ERA_element" args 84)("ERA_element" args 85)
("ERA_element" args 86)("ERA_element" args 87)("ERA_element" args 88)("ERA_element" args 89)("ERA_element" args 90)
("ERA_element" args 91)("ERA_element" args 92)("ERA_element" args 93)("ERA_element" args 94)("ERA_element" args 95)
("ERA_element" args 96)("ERA_element" args 97)("ERA_element" args 98)("ERA_element" args 99)("ERA_element" args 100)
("ERA_element" args 101)("ERA_element" args 102)("ERA_element" args 103)("ERA_element" args 104)("ERA_element" args 105)
("ERA_element" args 106)("ERA_element" args 107)("ERA_element" args 108)("ERA_element" args 109)("ERA_element" args 110)
("ERA_element" args 111)("ERA_element" args 112)("ERA_element" args 113)("ERA_element" args 114)("ERA_element" args 115)
("ERA_element" args 116)("ERA_element" args 117)("ERA_element" args 118)("ERA_element" args 119)("ERA_element" args 120)
("ERA_element" args 121)("ERA_element" args 122)("ERA_element" args 123)("ERA_element" args 124)("ERA_element" args 125)
("ERA_element" args 126)("ERA_element" args 127)("ERA_element" args 128)("ERA_element" args 129)("ERA_element" args 130)
	{armor
		{setting "d_a_front"	
			{thickness 75}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a1" "d_a2" "d_a3" "d_a4" "d_a5" "d_a6" "d_a7" "d_a8" "d_a37" "d_a38"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_front"
			{thickness 56}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a1" "comp_d_a2" "comp_d_a3" "comp_d_a4" "comp_d_a5" "comp_d_a6" "comp_d_a7" "comp_d_a8" "comp_d_a37" "comp_d_a38"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "d_a_side"	
			{thickness 40}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a9" "d_a10" "d_a18" "d_a19" "d_a20" "d_a33" "d_a34" "d_a35" "d_a36" "d_a39" 
					"d_a40" "d_a41" "d_a42" "d_a43" "d_a44" "d_a45" "d_a46" "d_a47" "d_a48" "d_a49" 
					"d_a50" "d_a51" "d_a52" "d_a53" "d_a54" "d_a59" "d_a60" "d_a61" "d_a62" "d_a71" 
					"d_a72" "d_a73" "d_a74" "d_a75" "d_a76" "d_a77"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_side"
			{thickness 290}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a9" "comp_d_a10" "comp_d_a18" "comp_d_a19" "comp_d_a20" "comp_d_a33" "comp_d_a34" "comp_d_a35" "comp_d_a36" "comp_d_a39" 
					"comp_d_a40" "comp_d_a41" "comp_d_a42" "comp_d_a43" "comp_d_a44" "comp_d_a45" "comp_d_a46" "comp_d_a47" "comp_d_a48" "comp_d_a49" 
					"comp_d_a50" "comp_d_a51" "comp_d_a52" "comp_d_a53" "comp_d_a54" "comp_d_a59" "comp_d_a60" "comp_d_a61" "comp_d_a62" "comp_d_a71" 
					"comp_d_a72" "comp_d_a73" "comp_d_a74" "comp_d_a75" "comp_d_a76" "comp_d_a77"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "d_a_turret"	
			{thickness 80}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a11" "d_a12" "d_a13" "d_a14" "d_a15" "d_a16" "d_a17" "d_a21" "d_a22" "d_a23"
					"d_a24" "d_a25" "d_a26" "d_a27" "d_a28" "d_a29" "d_a30" "d_a31" "d_a32" "d_a55"
					"d_a56" "d_a57" "d_a58" "d_a63" "d_a64" "d_a65" "d_a66" "d_a67" "d_a68" "d_a69"
					"d_a70" "d_a78" "d_a79" "d_a80" "d_a81" "d_a82" "d_a83" "d_a84" "d_a85" "d_a86"
					"d_a87" "d_a88" "d_a89" "d_a90" "d_a91" "d_a92" "d_a93" "d_a94" "d_a95" "d_a96"
					"d_a97" "d_a98" "d_a99" "d_a100" "d_a101" "d_a102" "d_a103" "d_a104" "d_a105" "d_a106"
					"d_a107" "d_a108" "d_a109" "d_a110" "d_a111" "d_a112" "d_a113" "d_a114" "d_a115" "d_a116"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a_turret"
			{thickness 50}
			{durability {blast {koef 12}} {pierce {value 120}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a11" "comp_d_a12" "comp_d_a13" "comp_d_a14" "comp_d_a15" "comp_d_a16" "comp_d_a17" "comp_d_a21" "comp_d_a22" "comp_d_a23"
					"comp_d_a24" "comp_d_a25" "comp_d_a26" "comp_d_a27" "comp_d_a28" "comp_d_a29" "comp_d_a30" "comp_d_a31" "comp_d_a32" "comp_d_a55"
					"comp_d_a56" "comp_d_a57" "comp_d_a58" "comp_d_a63" "comp_d_a64" "comp_d_a65" "comp_d_a66" "comp_d_a67" "comp_d_a68" "comp_d_a69"
					"comp_d_a70" "comp_d_a78" "comp_d_a79" "comp_d_a80" "comp_d_a81" "comp_d_a82" "comp_d_a83" "comp_d_a84" "comp_d_a85" "comp_d_a86"
					"comp_d_a87" "comp_d_a88" "comp_d_a89" "comp_d_a90" "comp_d_a91" "comp_d_a92" "comp_d_a93" "comp_d_a94" "comp_d_a95" "comp_d_a96"
					"comp_d_a97" "comp_d_a98" "comp_d_a99" "comp_d_a100" "comp_d_a101" "comp_d_a102" "comp_d_a103" "comp_d_a104" "comp_d_a105" "comp_d_a106"
					"comp_d_a107" "comp_d_a108" "comp_d_a109" "comp_d_a110" "comp_d_a111" "comp_d_a112" "comp_d_a113" "comp_d_a114" "comp_d_a115" "comp_d_a116"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)

(define "d_a_super_blazer"
	{armor
		{setting "d_a"
			{thickness 89}		
			{durability {blast {koef 2}} {pierce {value 180}}}
			{threshold {blast {koef 1}} {pierce {koef 0.166} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
;=========================================
(define "d_a_armorshieldke"
	("1gen_ERA")	;120 - 300, no exact data, see Eitan
	{armor
		{setting "d_a"
			{thickness 60}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
		{setting "comp_d_a"
			{thickness 90}
			{durability {blast {koef 12}} {pierce {value 75}}}
			{threshold {blast {koef 1}} {pierce {koef 2} 	{calibre 6}}}
			{volumes "comp_d_a*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
(define "nera"
	{component "nera1" {tags "nera"}}
	{component "nera2" {tags "nera"}}
	{component "nera3" {tags "nera"}}
	{component "nera4" {tags "nera"}}
	{component "nera5" {tags "nera"}}
	{component "nera6" {tags "nera"}}
	{component "nera7" {tags "nera"}}
	{component "nera8" {tags "nera"}}
	{component "nera9" {tags "nera"}}
	{component "nera10" {tags "nera"}}
	{component "nera11" {tags "nera"}}
	{component "nera12" {tags "nera"}}
	{component "nera13" {tags "nera"}}
	{component "nera14" {tags "nera"}}
	{component "nera15" {tags "nera"}}
	{component "nera16" {tags "nera"}}
	{component "nera17" {tags "nera"}}
	{component "nera18" {tags "nera"}}
	{component "nera19" {tags "nera"}}
	{component "nera20" {tags "nera"}}
	{component "nera21" {tags "nera"}}
	{component "nera22" {tags "nera"}}
	{component "nera23" {tags "nera"}}
	{component "nera24" {tags "nera"}}
	{component "nera25" {tags "nera"}}
	{component "nera26" {tags "nera"}}
	{component "nera27" {tags "nera"}}
	{component "nera28" {tags "nera"}}
	{component "nera29" {tags "nera"}}
	{component "nera30" {tags "nera"}}
	{armor
		{setting "nera"
			{thickness %thickness}
			{durability {blast {value 50}} {pierce {value 50}}}	
			{threshold {blast {koef 1}} {pierce {koef 0.166} 	{calibre 6}}}
			{volumes "nera*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
(define "nera_extended"	;do not use with full d_a settings, 
	{component "nera1" {tags "nera"}}
	{component "nera2" {tags "nera"}}
	{component "nera3" {tags "nera"}}
	{component "nera4" {tags "nera"}}
	{component "nera5" {tags "nera"}}
	{component "nera6" {tags "nera"}}
	{component "nera7" {tags "nera"}}
	{component "nera8" {tags "nera"}}
	{component "nera9" {tags "nera"}}
	{component "nera10" {tags "nera"}}
	{component "nera11" {tags "nera"}}
	{component "nera12" {tags "nera"}}
	{component "nera13" {tags "nera"}}
	{component "nera14" {tags "nera"}}
	{component "nera15" {tags "nera"}}
	{component "nera16" {tags "nera"}}
	{component "nera17" {tags "nera"}}
	{component "nera18" {tags "nera"}}
	{component "nera19" {tags "nera"}}
	{component "nera20" {tags "nera"}}
	{component "nera21" {tags "nera"}}
	{component "nera22" {tags "nera"}}
	{component "nera23" {tags "nera"}}
	{component "nera24" {tags "nera"}}
	{component "nera25" {tags "nera"}}
	{component "nera26" {tags "nera"}}
	{component "nera27" {tags "nera"}}
	{component "nera28" {tags "nera"}}
	{component "nera29" {tags "nera"}}
	{component "nera30" {tags "nera"}}
	{component "nera31" {tags "nera"}}
	{component "nera32" {tags "nera"}}
	{component "nera33" {tags "nera"}}
	{component "nera34" {tags "nera"}}
	{component "nera35" {tags "nera"}}
	{component "nera36" {tags "nera"}}
	{component "nera37" {tags "nera"}}
	{component "nera38" {tags "nera"}}
	{component "nera39" {tags "nera"}}
	{component "nera40" {tags "nera"}}
	{component "nera41" {tags "nera"}}
	{component "nera42" {tags "nera"}}
	{component "nera43" {tags "nera"}}
	{component "nera44" {tags "nera"}}
	{component "nera45" {tags "nera"}}
	{component "nera46" {tags "nera"}}
	{component "nera47" {tags "nera"}}
	{component "nera48" {tags "nera"}}
	{component "nera49" {tags "nera"}}
	{component "nera50" {tags "nera"}}
	{component "nera51" {tags "nera"}}
	{component "nera52" {tags "nera"}}
	{component "nera53" {tags "nera"}}
	{component "nera54" {tags "nera"}}
	{component "nera55" {tags "nera"}}
	{component "nera56" {tags "nera"}}
	{component "nera57" {tags "nera"}}
	{component "nera58" {tags "nera"}}
	{component "nera59" {tags "nera"}}
	{component "nera60" {tags "nera"}}
	{component "nera61" {tags "nera"}}
	{component "nera62" {tags "nera"}}
	{component "nera63" {tags "nera"}}
	{component "nera64" {tags "nera"}}
	{component "nera65" {tags "nera"}}
	{component "nera66" {tags "nera"}}
	{component "nera67" {tags "nera"}}
	{component "nera68" {tags "nera"}}
	{component "nera69" {tags "nera"}}
	{component "nera70" {tags "nera"}}
	{component "nera71" {tags "nera"}}
	{component "nera72" {tags "nera"}}
	{component "nera73" {tags "nera"}}
	{component "nera74" {tags "nera"}}
	{component "nera75" {tags "nera"}}
	{component "nera76" {tags "nera"}}
	{component "nera77" {tags "nera"}}
	{component "nera78" {tags "nera"}}
	{component "nera79" {tags "nera"}}
	{component "nera80" {tags "nera"}}
	{component "nera81" {tags "nera"}}
	{component "nera82" {tags "nera"}}
	{component "nera83" {tags "nera"}}
	{component "nera84" {tags "nera"}}
	{component "nera85" {tags "nera"}}
	{component "nera86" {tags "nera"}}
	{component "nera87" {tags "nera"}}
	{component "nera88" {tags "nera"}}
	{component "nera89" {tags "nera"}}
	{component "nera90" {tags "nera"}}
	{armor
		{setting "nera"
			{thickness %thickness}
			{durability {blast {value 50}} {pierce {value 50}}}	
			{threshold {blast {koef 1}} {pierce {koef 0.166} 	{calibre 6}}}
			{volumes "nera*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)

(define "kaz_arena_armor"
	{Volume "kaz_hitzone_01" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_02" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_03" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_04" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_05" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_06" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_07" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_08" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_09" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_10" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_11" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_12" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_13" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_14" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_15" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_16" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_17" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_18" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_19" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_20" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_21" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_22" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_23" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_24" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_25" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_26" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_27" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_28" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_29" {thickness 0.1} {tags "kaz_hitzone"  "kaz_touch"} {able {NoWoundDecal} {obstacle 0} {touch 0}} {component "kaz1"}}

    {component "kaz1"}

	{Volume "kaz_01" {thickness 20} {tags "kaz_touch"} {able {touch 0}}{component "kaz01"}} {component "kaz01" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_02" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz02"}} {component "kaz02" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_03" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz03"}} {component "kaz03" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_04" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz04"}} {component "kaz04" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_05" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz05"}} {component "kaz05" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_06" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz06"}} {component "kaz06" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_07" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz07"}} {component "kaz07" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_08" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz08"}} {component "kaz08" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_09" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz09"}} {component "kaz09" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_10" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz10"}} {component "kaz10" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_11" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz11"}} {component "kaz11" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_12" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz12"}} {component "kaz12" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_13" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz13"}} {component "kaz13" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_14" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz14"}} {component "kaz14" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_15" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz15"}} {component "kaz15" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_16" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz16"}} {component "kaz16" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_17" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz17"}} {component "kaz17" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_18" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz18"}} {component "kaz18" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_19" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz19"}} {component "kaz19" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_20" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz20"}} {component "kaz20" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_21" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz21"}} {component "kaz21" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_22" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz22"}} {component "kaz22" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_23" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz23"}} {component "kaz23" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_24" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz24"}} {component "kaz24" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_25" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz25"}} {component "kaz25" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_26" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz26"}} {component "kaz26" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_27" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz26"}} {component "kaz26" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_28" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz26"}} {component "kaz26" {tags "kaz"}{RepairTime 5}}
	{Volume "kaz_29" {thickness 20} {tags "kaz_touch"} {able {touch 0}} {component "kaz26"}} {component "kaz26" {tags "kaz"}{RepairTime 5}}
)
(define "kaz_afganit"
	("kaz_arena_armor")
	{Volume "kaz_hitzone_01a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_02a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_03a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_04a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_05a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_06a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_07a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_08a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_09a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_10a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_11a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_12a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_13a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_14a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_15a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_16a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_17a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_18a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_19a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_20a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_21a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_22a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_23a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_24a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_25a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_26a" {thickness 0.1} {tags "kaz_hitzonea"  "kaz_hitzone"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{armor
		{setting "kaz_hitzonea"
			{thickness 450 150 150 150}		
			{durability {blast {value 999}} {pierce {koef 999}}}
			{threshold {blast {value 999}}{pierce {koef 999}}}
			{volumes "kaz_hitzone_01a" "kaz_hitzone_02a" "kaz_hitzone_03a" "kaz_hitzone_04a" "kaz_hitzone_05a"
			"kaz_hitzone_06a" "kaz_hitzone_07a" "kaz_hitzone_08a" "kaz_hitzone_09a" "kaz_hitzone_10a"
			"kaz_hitzone_11a" "kaz_hitzone_12a" "kaz_hitzone_13a" "kaz_hitzone_14a" "kaz_hitzone_15a"
			"kaz_hitzone_16a" "kaz_hitzone_17a" "kaz_hitzone_18a" "kaz_hitzone_19a" "kaz_hitzone_20a"
			"kaz_hitzone_21a" "kaz_hitzone_22a" "kaz_hitzone_23a" "kaz_hitzone_24a" "kaz_hitzone_25a"
			"kaz_hitzone_26a"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)

(define "kaz_trophy_armor"
	{Volume "kaz_hitzone_l1" {thickness 0.1} {tags "kaz_hitzone" "trophy_left"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_l2" {thickness 0.1} {tags "kaz_hitzone" "trophy_left"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_l3" {thickness 0.1} {tags "kaz_hitzone" "trophy_left"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_l4" {thickness 0.1} {tags "kaz_hitzone" "trophy_left"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_r1" {thickness 0.1} {tags "kaz_hitzone" "trophy_right"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_r2" {thickness 0.1} {tags "kaz_hitzone" "trophy_right"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_r3" {thickness 0.1} {tags "kaz_hitzone" "trophy_right"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
	{Volume "kaz_hitzone_r4" {thickness 0.1} {tags "kaz_hitzone" "trophy_right"} {able {NoWoundDecal} {obstacle 0}} {component "kaz1"}}
    {component "kaz1"}

	{volume "trophy_radar_l1" {thickness 10} {component "trophy_radar_l1"}}
	{component "trophy_radar_l1"}
	{volume "trophy_radar_l2" {thickness 10} {component "trophy_radar_l2"}}
	{component "trophy_radar_l2"}
	{volume "trophy_radar_r1" {thickness 10} {component "trophy_radar_r1"}}
	{component "trophy_radar_r1"}
	{volume "trophy_radar_r2" {thickness 10} {component "trophy_radar_r2"}}
	{component "trophy_radar_r2"}

	{volume "trophy_mortar_l" {thickness 10} {component "trophy_mortar_l"}}
	{component "trophy_mortar_l" {RepairTime 20} }
	{volume "trophy_mortar_r" {thickness 10} {component "trophy_mortar_r"}}
	{component "trophy_mortar_r" {RepairTime 20} }
)
(define "mrap_addon"
	{armor
		{setting "mrap"
			{thickness %mrap}
			{durability
                {blast {koef 1} {value %mrap_val} } {pierce {value %mrap_val} }
            }
            {threshold
                {blast {koef 1} }{pierce {koef 1}}
            }			
			{volumes "mrap*"}
			{health_reducing {pierce {koef 0.0001}} {blast {koef 0.0001}} }
		}
	}
)
(define "mrap_addon_civilian"
    ("mrap_addon" mrap(1) mrap_val(1))
)
(define "mrap_addon_truck"
    ("mrap_addon" mrap(1) mrap_val(1))
)
(define "mrap_addon_BR1"
    ("mrap_addon" mrap(1) mrap_val(1))
)
(define "mrap_addon_BR2"
    ("mrap_addon"  mrap(1) mrap_val(1))
)
(define "mrap_addon_BR3"
    ("mrap_addon"  mrap(1) mrap_val(1))
)
(define "mrap_addon_STANAG1"
    ("mrap_addon" mrap(1) mrap_val(1))
)
(define "mrap_addon_BR4"
    ("mrap_addon" mrap(1) mrap_val(1))
)
(define "mrap_addon_STANAG2a"	
    ("mrap_addon" mrap(5) mrap_val(5))
)
(define "mrap_addon_STANAG2b"
    ("mrap_addon" mrap(8) mrap_val(8))
)
(define "mrap_addon_BR5"
    ("mrap_addon" mrap(15) mrap_val(80))
)
(define "mrap_addon_STANAG3a"	
    ("mrap_addon" mrap(15) mrap_val(80))
)
(define "mrap_addon_STANAG3b"
    ("mrap_addon" mrap(18) mrap_val(90))
)
(define "mrap_addon_BR6"
    ("mrap_addon" mrap(20) mrap_val(100))
)
(define "mrap_addon_STANAG4"
    ("mrap_addon" mrap(20) mrap_val(100))
)