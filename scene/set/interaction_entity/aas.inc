;COLD WAR MOD
;Scripted by Timosh
;aas events for all ground vehicles including cars.
{"aas_vehicle"
	{on spawn
		{volumes "component_internal" enable blast}
		{set "pierce" 0}
		{call "update_crew_vol"}
	}
	{on pierce
		{if component "body" or component "turret"
			{set "pierce" 1}
			{delay 0.45 {set "pierce" 0}}
		else component "engine"
		  {if not flag "engine_started"
			{if rand 0.15
				{call "_burn"}
			}
		  else
			{if rand 0.30
				{call "_burn"}
			}
		  }
		else component "transmission"
			{if rand 0.15
				{call "_burn"}
			}
		else component "autoloader"
			{if rand 0.15
				{call "_burn"}
			}
		else component "stabilizer"
			{if rand 0.15
				{call "_burn"}
			}
		else component "apu"
			{if rand 0.15
				{burn fx "smoke_dead_norm" fake}
				{call "_burn"}
			}
		else component "ammo_storage_main"
				{if explosive_amount 4000	;bit more than fully loaded Msta-S
					{call "ammo_damage800"}
				else explosive_amount 3000
					{call "ammo_damage400"}
				else explosive_amount 2000		
					{call "ammo_damage200"}
				else explosive_amount 1000		;fully loaded M1A1HA or T-72
					{call "ammo_damage130"}
				else explosive_amount 750		;M1A1HA or T-72 after several shots - 1/4 ammo depleted
					{call "ammo_damage100"}
				else explosive_amount 500
					{call "ammo_damage70"}
				else explosive_amount 250
					{call "ammo_damage30"}
				else explosive_amount 100
					{call "ammo_damage10"}
				}
		}
		{delay 0.1 {call "update_crew_vol"}}
	}
	{on blast_hit
	  {if not flag "pierce"
		{volumes "component_internal" disable blast} {volumes "crew_internal" disable blast}
		{delay 0.5 {volumes "component_internal" enable blast}{call "update_crew_vol"} }
	  }
	}	
	
	
	{on "_burnout"
		{call "stat_break"}
		{add_view "engine_fire" "deathfx" "FXfire1"}
	}
	{on "init_burnout"
		{add_view "fire_ammo_burnout1" "ammo_burnout1" "FXfire3"}
		{add_view "fire_ammo_burnout2" "ammo_burnout2" "FXfire3"}
		{add_view "fire_ammo_burnout3" "ammo_burnout3" "FXfire3"}
		{add_view "fire_ammo_burnout4" "ammo_burnout4" "FXfire3"}
	}
	{on "ammo_burnout"
		{call "burnout"}
		{if rand 0.25 {call "kill_crew"}}
		{delay 1	{crew_emit}}
		{delay 2	{crew_emit}}
		{delay 3	{crew_emit}}
;		{call "blow_burnout"}
		{delay_ex 0
;			{add_view "fire_ammo_burnout1" "ammo_burnout1" "FXfire3"}
			{start_sound "detonation/ammo_burnout"}
			{view start "ammo_burnout1"}
			{delay 1.4 0.4
;				{add_view "fire_ammo_burnout2" "ammo_burnout2" "FXfire3"}
				{view start "ammo_burnout2"}
			}
			{delay 3 1
;				{add_view "fire_ammo_burnout3" "ammo_burnout3" "FXfire3"}
				{view start "ammo_burnout3"}
			}
			{delay 5 1
;				{add_view "fire_ammo_burnout4" "ammo_burnout4" "FXfire3"}
				{view start "ammo_burnout4"}
			}
		}
	}
	{on "ammo_burnout_detonate"
	        ;{delay_ex 1 {spawn "ex_air_big2" "basis" inv_normal}}
		    {delay_ex 1  {crew_emit}}
			{delay_ex 2  {crew_emit}}
			{delay_ex 3  {crew_emit}}	
			{delay_ex 3.5 {call "ammo_burnout"}}
            {delay_ex 7 0.5 {spawn "ex_air_big2" "basis" inv_normal}}
			{delay_ex 9 0.5 {spawn "ex_air_big2" "basis" inv_normal}}
			{delay_ex 11 0.5 {spawn "ex_air_big2" "basis" inv_normal} {fragments c4 6 r0 4 r1 8 position}}
			{delay_ex 13 0.5 {spawn "ex_air_big2" "basis" inv_normal} {fragments c4 6 r0 4 r1 8 position}}				
	}
	{on "ammo_damage800"
		{if not inventory_item "size2 fg" and not inventory_item "size3 fg" and not inventory_item "size4 fg"
			{if rand 0.6 {call "ammo_burnout_detonate"}
				{if rand 0.6 {delay_ex 15.5 1.5 {spawn "cw_explosion_200kg" "basis"}{call "_explosion"}}}
				else
				{spawn "ex_air_big2" "basis"} {blastwave c4 16 r0 7 r1 14 position}
				{delay_ex 0.2 0.1 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 14 r0 6 r1 12 position}}
				{delay_ex 0.3 0.1 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 12 r0 5 r1 10 position}}
				{delay_ex 0.4 0.1 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 10 r0 5 r1 10 position}}
				{delay 1	{crew_emit}}
				{delay 2	{crew_emit}}
				{delay 3	{crew_emit}}
				{if rand 0.8 {spawn "cw_explosion_1000kg" "basis"}{call "_explosion"}}
			}
		else rand 0.3 {call "ammo_burnout"}
		else {spawn "cw_explosion_1000kg" "basis"}{call "_explosion"}
		}
		{clear_inventory}{tags add "cwfs_set_fuel"}
	}
	{on "ammo_damage400"
		{if not inventory_item "size2 fg" and not inventory_item "size3 fg" and not inventory_item "size4 fg"
			{if rand 0.6 {call "ammo_burnout_detonate"}
			   {if rand 0.6 {delay_ex 15.5 1.5 {spawn "cw_explosion_200kg" "basis"}{call "_explosion"}}}
				else
				{spawn "ex_air_big2" "basis"} {blastwave c4 12 r0 7 r1 14 position}
				{delay_ex 0.2 0.1 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 10 r0 6 r1 12 position}}
				{delay_ex 0.6 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 8 r0 5 r1 10 position}}
				{delay_ex 1 0.2 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 7 r0 4 r1 8 position}}
				{delay_ex 1.3 0.5 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 7 r0 4 r1 8 position}}
				{delay 1	{crew_emit}}
				{delay 2	{crew_emit}}
				{delay 3	{crew_emit}}
				{if rand 0.6 {spawn "cw_explosion_200kg" "basis"}{call "_explosion"}}
			}
		else rand 0.35 {call "ammo_burnout"}
		else {spawn "cw_explosion_200kg" "basis"}{call "_explosion"}
		}
		{clear_inventory}{tags add "cwfs_set_fuel"}
	}
	{on "ammo_damage200"
		{if not inventory_item "size2 fg" and not inventory_item "size3 fg" and not inventory_item "size4 fg"
			{if rand 0.6 {call "ammo_burnout"}
			else rand 0.5
				{spawn "ex_air_big2" "basis"} {blastwave c4 9 r0 5 r1 10 position}
				{delay_ex 0.2 0.1 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 8 r0 5 r1 10 position}}
				{delay_ex 0.6 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 8 r0 5 r1 10 position}}
				{delay_ex 1 0.2 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 7 r0 4 r1 8 position}}
				{delay_ex 1.3 0.2 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 7 r0 4 r1 8 position}}
				{delay_ex 1.6 0.7 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 6 r0 4 r1 8 position}}
				{delay 1	{crew_emit}}
				{delay 2	{crew_emit}}
				{delay 3	{crew_emit}}				
				{if rand 0.36 {spawn "cw_explosion_200kg" "basis"}{call "_explosion"}}
			 else 
				{call "ammo_burnout_detonate"}
				{if rand 0.36 {delay_ex 15.5 1.5 {spawn "cw_explosion_200kg" "basis"}{call "_explosion"}}}
			}
		else rand 0.4 {call "ammo_burnout"}
		else {spawn "cw_explosion_200kg" "basis"}{call "_explosion"}
		}
		{clear_inventory}{tags add "cwfs_set_fuel"}
	}
	{on "ammo_damage130"
		{if not inventory_item "size2 fg" and not inventory_item "size3 fg" and not inventory_item "size4 fg"
			{if rand 0.7 {call "ammo_burnout"}
			else rand 0.5
				{spawn "ex_air_big2" "basis"} {blastwave c4 8 r0 5 r1 10 position}
				{delay_ex 0.2 0.1 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 7 r0 5 r1 10 position}}
				{delay_ex 0.6 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 7 r0 5 r1 10 position}}
				{delay_ex 1 0.2 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 6 r0 4 r1 8 position}}
				{delay_ex 1.3 0.5 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 6 r0 4 r1 8 position}}
				{delay_ex 1.6 0.7 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 6 r0 4 r1 8 position}}
				{delay 1	{crew_emit}}
				{delay 2	{crew_emit}}
				{delay 3	{crew_emit}}				
				{if rand 0.36 {spawn "cw_explosion_50kg" "basis"}{call "_explosion"}}
			 else
				{call "ammo_burnout_detonate"}
				{if rand 0.36 {delay_ex 15.5 1.5 {spawn "cw_explosion_50kg" "basis"}{call "_explosion"}}}
			}
		else rand 0.45 {call "ammo_burnout"}
		else {spawn "cw_explosion_50kg" "basis"}{call "_explosion"}
		}
		{clear_inventory}{tags add "cwfs_set_fuel"}
	}
	{on "ammo_damage100"
		{if not inventory_item "size2 fg" and not inventory_item "size3 fg" and not inventory_item "size4 fg"
			{if rand 0.85 {call "ammo_burnout"}
			else rand 0.4
				{spawn "ex_air_big2" "basis"} {blastwave c4 6 r0 4 r1 8 position}
				{delay_ex 0.2 0.1 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 6 r0 4 r1 8 position}}
				{delay_ex 0.6 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 6 r0 4 r1 8 position}}
				{delay_ex 1 0.2 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 6 r0 4 r1 8 position}}
				{delay_ex 1.3 0.5 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 6 r0 4 r1 8 position}}
				{delay 1	{crew_emit}}
				{delay 2	{crew_emit}}
				{delay 3	{crew_emit}}				
				{if rand 0.29 {spawn "cw_explosion_50kg" "basis"}{call "_explosion"}}
			 else
				 {call "ammo_burnout_detonate"}
				{if rand 0.2  {delay_ex 15.5 1.0 {spawn "cw_explosion_50kg" "basis"}{call "_explosion"}}}
			}
		else rand 0.5 {call "ammo_burnout"}
		else {spawn "cw_explosion_50kg" "basis"}{call "_explosion"}
		}
		{clear_inventory}{tags add "cwfs_set_fuel"}
	}
	{on "ammo_damage70"
		{if not inventory_item "size2 fg" and not inventory_item "size3 fg" and not inventory_item "size4 fg"
			{if rand 0.85 {call "ammo_burnout"}
			else
				{spawn "ex_air_big2" "basis"} {blastwave c4 6 r0 4 r1 8 position}
				{delay_ex 0.2 0.1 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 6 r0 4 r1 8 position}}
				{delay_ex 0.6 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 5 r0 3 r1 6 position}}
				{delay_ex 1 0.2 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 5 r0 3 r1 6 position}}
				{delay 1	{crew_emit}}
				{delay 2	{crew_emit}}
				{delay 3	{crew_emit}}				
				{if rand 0.29 {delay_ex 8.5 1.0  {spawn "cw_explosion_10kg" "basis"}{call "_explosion"}}}
			}
		else rand 0.6 {call "ammo_burnout"}
		else {spawn "cw_explosion_10kg" "basis"}{call "_explosion"}
		}
		{clear_inventory}{tags add "cwfs_set_fuel"}
	}
	{on "ammo_damage30"
		{if not inventory_item "size2 fg" and not inventory_item "size3 fg" and not inventory_item "size4 fg"
			{if rand 0.9 {call "ammo_burnout"}
			else
				{spawn "ex_air_big2" "basis"} {blastwave c4 4 r0 3 r1 6 position}
				{delay_ex 0.2 0.1 {spawn "ex_air_big2" "basis" inv_normal} {blastwave c4 4 r0 3 r1 6 position}}
				{delay 1	{crew_emit}}
				{delay 2	{crew_emit}}
				{delay 3	{crew_emit}}				
			}
		else rand 0.7 {call "ammo_burnout"}
		else {spawn "cw_explosion_10kg" "basis"}{call "_explosion"}
		}
		{clear_inventory}{tags add "cwfs_set_fuel"}
	}
	{on "ammo_damage10"
		{if rand 0.95 {clear_inventory}{tags add "cwfs_set_fuel"}}
	}
	{on "break_all" overload
		{kill_crew}
		{drop_orders}
		{components "body" destroy}
		{components "cabin" destroy}
		{components "turret" destroy}
		{components "gun" destroy}
		{components "wheelleft1" destroy}
		{components "wheelright1" destroy}
		{components "wheelleft2" destroy}
		{components "wheelright2" destroy}
		{components "wheelleft3" destroy}
		{components "wheelright3" destroy}
		{components "wheelleft4" destroy}
		{components "wheelright4" destroy}
		{components "engine" destroy}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
		{clear_inventory}
	}
	{on fragments
		;при срабатывании on fragments осколок только один, но дамажатся все волумы юнита
		;и вдобавок сечение юнита порядка 10м2, а компоненты маленькие.
		;p - это вероятность того, что осколок попал в данный компонент, если он попал в площадь 2м2
		;например, прицел имеет площадь проекции в целом 0,3м2, так что шанс 0.3/2=0.15

		(define "frag_to_blast" 
		
		(define "check_damage_frag"
			else component "%component" 
			 {if rand %p or not stuff "ammo"
			  {if rand %splitter {spawn "metal_hit_bul"}}
			  {blastwave c4 (+ %e 0.2) r0 0.04 r1 0.05 position} 
			 }
		)
		(define "check_damage_crew"
		  else volume "%crew_place" work and min_energy 0.3
				(define "kill_crew"
					{if crew_in_place "%crew"
					 {damage_report "body" "%msg"}
					}
					{kill_crew "%crew"}{icon_event "crew_dead" 10}
					{crew_enable place "%crew" 0} {set "crew_tempdisabled" 1}
					{delay 10 {crew_enable place "%crew" 1} {set "crew_tempdisabled" 0}}
				)
			 {if min_energy 1.3 ("kill_crew")
			 else  min_energy 1.0  and rand 0.8 ("kill_crew")
			 else  min_energy 0.7  and rand 0.5 ("kill_crew")
			 else  min_energy 0.5  and rand 0.3 ("kill_crew")
			 else rand 0.15 ("kill_crew")
			}
		)
		(define "check_damage_desant"
		  else volume "%crew_place" work and min_energy 0.3
		  		(define "kill_crew"
					{kill_crew "%crew"}{icon_event "crew_dead" 2}
				)
			 {if min_energy 1.3 ("kill_crew")
			 else  min_energy 1.0  and rand 0.8 ("kill_crew")
			 else  min_energy 0.7  and rand 0.5 ("kill_crew")
			 else  min_energy 0.5  and rand 0.3 ("kill_crew")
			 else rand 0.15 ("kill_crew")
			}
		)
		min_energy %e 
		 {if component "d_a" or component "nera" {if rand 0.1   {blastwave c4 (+ %e 0.2) r0 0.01 r1 0.02 position}{spawn "metal_hit_bul"}}
		("check_damage_frag" component(engine)  p(1) splitter(%splitter))
		("check_damage_frag" component(driver_panel)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(transmission)  p(0.8) splitter(%splitter))
		("check_damage_frag" component(autoloader)  p(1) splitter(%splitter))
		("check_damage_frag" component(mgun)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun1)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun2)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun3)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun4)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun5)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun6)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun20)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(mgun21)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(turret_ring)  p(0.5) splitter(%splitter))
		("check_damage_frag" component(panel_engine_connectors)  p(0.4) splitter(%splitter))
		("check_damage_frag" component(turret_move_engine)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(front_wheels)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(stabilizer)  p(0.35) splitter(%splitter))
		("check_damage_frag" component(gunner_panel)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(PPU)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(APU)  p(0.75) splitter(%splitter))
		("check_damage_frag" component(driver_triplex)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(commander_triplex)  p(0.25) splitter(%splitter))
		("check_damage_frag" component(additional_triplex)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(additional_triplex1)  p(0.15) splitter(%splitter))
		("check_damage_frag" component(additional_triplex2)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(additional_triplex3)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(additional_triplex4)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(additional_triplex5)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(shtora_visor)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(shtora_visor1)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(shtora_visor2)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(shtora_visor3)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(ammo_storage_main)  p(1) splitter(%splitter))	;они большие, по 3м2
		("check_damage_frag" component(ammo_storage_autocannon)  p(0.5) splitter(%splitter))
		("check_damage_frag" component(ammo_storage_mgun)  p(0.1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_internal_a)  p(0.7) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_internal_b)  p(0.7) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_internal_c)  p(0.7) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_internal_d)  p(0.7) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_a)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_b)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_c)  p(1) splitter(%splitter))
		("check_damage_frag" component(fuel_tank_external_d)  p(1) splitter(%splitter))
		("check_damage_frag" component(gun)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(gun1)  p(0.2) splitter(%splitter))
		("check_damage_frag" component(gun2)  p(0.3) splitter(%splitter))
		("check_damage_frag" component(gun3)  p(0.3) splitter(%splitter))
		("check_damage_crew" crew(driver) msg(driver_dead))
		("check_damage_crew" crew(driver1) msg(driver_dead))
		("check_damage_crew" crew(gunner) msg(shooter_dead))
		("check_damage_crew" crew(gunner1) msg(shooter_dead))
		("check_damage_crew" crew(gunner2) msg(shooter_dead))
		("check_damage_crew" crew(charger) msg(charger_dead))
		("check_damage_crew" crew(commander) msg(commander_dead))
		("check_damage_crew" crew(commander1) msg(commander_dead))
		("check_damage_desant" crew(seat1) )
		("check_damage_desant" crew(seat2) )
		("check_damage_desant" crew(seat3) )
		("check_damage_desant" crew(seat4) )
		("check_damage_desant" crew(seat5) )
		("check_damage_desant" crew(seat6) )
		("check_damage_desant" crew(seat7) )
		("check_damage_desant" crew(seat8) )
		("check_damage_desant" crew(seat9) )
		("check_damage_desant" crew(seat10) )
		("check_damage_desant" crew(seat11) )
		("check_damage_desant" crew(seat12) )
		("check_damage_desant" crew(seat13) )
		("check_damage_desant" crew(seat14) )
		("check_damage_desant" crew(seat15) )
		("check_damage_desant" crew(seat16) )
		("check_damage_desant" crew(seat17) )
		("check_damage_desant" crew(seat18) )
		("check_damage_desant" crew(seat19) )
		("check_damage_desant" crew(seat20) )
		("check_damage_desant" crew(seat21) )
		("check_damage_desant" crew(seat22) )
		("check_damage_desant" crew(seat23) )
		("check_damage_desant" crew(seat24) )
		("check_damage_desant" crew(seat25) )
		 else {blastwave c4 (+ %e 0.2) r0 0.04 r1 0.05 position}{if rand 0.1{spawn "metal_hit_bul"}}
		}
		)
		{if ("frag_to_blast" e(54.9) splitter(1))
		else ("frag_to_blast" e(49.9) splitter(1))
		else ("frag_to_blast" e(44.9) splitter(1))
		else ("frag_to_blast" e(39.9) splitter(1))
		else ("frag_to_blast" e(34.9) splitter(1))
		else ("frag_to_blast" e(29.9) splitter(1))
		else ("frag_to_blast" e(27.9) splitter(1))
		else ("frag_to_blast" e(24.9) splitter(1))
		else ("frag_to_blast" e(21.9) splitter(1))
		else ("frag_to_blast" e(19.9) splitter(1))
		else ("frag_to_blast" e(17.9) splitter(1))
		else ("frag_to_blast" e(15.9) splitter(1))
		else ("frag_to_blast" e(13.4) splitter(1))
		else ("frag_to_blast" e(10.9) splitter(1))
		else ("frag_to_blast" e(9.9) splitter(1))
		else ("frag_to_blast" e(7.9) splitter(1))
		else ("frag_to_blast" e(6.4) splitter(1))
		else ("frag_to_blast" e(4.9) splitter(1))
		else ("frag_to_blast" e(3.9) splitter(0.7))
		else ("frag_to_blast" e(2.9) splitter(0.4))
		else ("frag_to_blast" e(2.4) splitter(0.2))
		else ("frag_to_blast" e(1.9) splitter(0.2))
		else ("frag_to_blast" e(1.4) splitter(0.2))
		else ("frag_to_blast" e(0.9) splitter(0.2))
		else ("frag_to_blast" e(0.6) splitter(0.2))
		else ("frag_to_blast" e(0.4) splitter(0))
		}
		
	}
	{on break

;After-armor system by Timosh
;defines of "break" events
		;=========================
		;mover parts and engine
		;=========================
        {if not user_control
	         {if not stuff "bullet"
		       {delay 3
		        {if rand 0.5
				  {if component "move_indicator" or component "power_indicator"
				  else {call "smokescreen"}}
		        }
	           }
	         }
	    }		
		{if component "driver_panel"
			{chassis_work 0} {components "move_indicator" break}
			{tags add "driver_panel_damaged"}
			{if not tagged "destroyed"
				{damage_report "driver_panel" "driver_panel_damaged"}
			}
			{spawn "tank_die_particle" "body"}
			{if not tagged "crit_system_destroyed"
				{tags add "crit_system_destroyed"}
			else
				{if not tagged "crit_system_destroyed2"
				    {tags add "crit_system_destroyed2"}
				else
					{components "body" break}
				}	  
			}
		else component "transmission"
			{chassis_work 0} {components "move_indicator" break}
			{tags add "transmission_damaged"}
			{if flag "engine_started" {play_sound "engine_broken"}}
			{if not tagged "destroyed"
				{damage_report "transmission" "transmission_damaged"}
			}
			{spawn "tank_die_particle" "Body"}
			{if not tagged "crit_system_destroyed"
				{tags add "crit_system_destroyed"}
			else
				{if not tagged "crit_system_destroyed2"
				   {tags add "crit_system_destroyed2"}
				 else
				    {components "body" break}
				}	  
			}
		else component "panel_engine_connectors"
			{chassis_work 0} {components "move_indicator" break}
			{if not tagged "destroyed"
				{damage_report "panel_engine_connectors" "panel_engine_connectors_damaged"}
			}
			{spawn "tank_die_particle" "Body"}
			{tags add "panel_engine_connectors_damaged"}
			{if not tagged "crit_system_destroyed"
				{tags add "crit_system_destroyed"}
			else
				{if not tagged "crit_system_destroyed2"
				   {tags add "crit_system_destroyed2"}
				else
				   {components "body" break}
				}	  
			}
		else component "front_wheels"
			{if not tagged "destroyed"
				{damage_report "front_wheels" "front_wheels_damaged"}
			}
			{spawn "tank_die_particle" "Body"}
			;=========================
			;ammo amd fuel
			;=========================
		else component "ammo_storage_autocannon"
				{spawn "ex_air_big"}
				{fragments c4 3 r0 2 r1 6}
				{delay_ex 0.2 0.5
					{spawn "ex_air_big" inv_normal}
					{fragments c4 3 r0 2 r1 6 position}
				}
				{delay_ex  0.6 1
					{spawn "ex_air_big" inv_normal}
					{fragments c4 3 r0 2 r1 6 position}
				}
				{delay_ex 1 1.2
					{spawn "ex_air_big" inv_normal}
					{fragments c4 3 r0 2 r1 6 position}
				}
				{delay_ex 1.3 1.5
					{spawn "ex_air_big" inv_normal}
					{fragments c4 3 r0 2 r1 6 position}
				}
				{if rand 0.3 {clear_inventory}{tags add "cwfs_set_fuel"}}
				{if rand 0.2 {call "ammo_burnout"}}
		else component "ammo_storage_mgun" 
				{spawn "ex_air_norm"}
				{fragments c4 2 r0 1 r1 3 position}
				{delay_ex 0.2 0.5
					{spawn "ex_air_norm" inv_normal}
					{fragments c4 2 r0 1 r1 3 position}
				}
				{delay_ex  0.6 1
					{spawn "ex_air_norm" inv_normal}
					{fragments c4 2 r0 1 r1 3 position}
				}
				{delay_ex 1 1.2
					{spawn "ex_air_norm" inv_normal}
					{fragments c4 2 r0 1 r1 3 position}
				}
				{delay_ex 1.3 1.5
					{spawn "ex_air_norm" inv_normal}
					{fragments c4 2 r0 1 r1 3 position}
				}
		else component "fuel_tank_internal_a"
			{if not tagged "destroyed"
				{damage_report "fuel_tank_external_a" "fuel:fuel_tank_damaged"}
			}
			{if rand 0.8
				{burn fx "smoke_dead_norm" fake}
				{fire radius 4 time 1 heating 3}
				{call "_burn"}
				{if rand 0.8
					{spawn "ex_air_big"}
				}
				{delay 1 {crew_emit}}
				{delay 2 {crew_emit}}
				{delay 3 {crew_emit}}
			}
		else component "fuel_tank_internal_b"
			{if not tagged "destroyed"
				{damage_report "fuel_tank_external_b" "fuel:fuel_tank_damaged"}
			}
			{if rand 0.8
				{burn fx "smoke_dead_norm" fake}
				{fire radius 4 time 1 heating 3}
				{call "_burn"}
				{if rand 0.8
					{spawn "ex_air_big"}
				}
				{delay 1 {crew_emit}}
				{delay 2 {crew_emit}}
				{delay 3 {crew_emit}}
			}

		else component "fuel_tank_internal_c"
			{if not tagged "destroyed"
				{damage_report "fuel_tank_external_c" "fuel:fuel_tank_damaged"}
			}
			{if rand 0.8
				{burn fx "smoke_dead_norm" fake}
				{fire radius 4 time 1 heating 3}
				{call "_burn"}
				{if rand 0.8
					{spawn "ex_air_big"}
	;				{blastwave c4 3 r0 2 r1 6 position}
				}
				{delay 1 {crew_emit}}
				{delay 2 {crew_emit}}
				{delay 3 {crew_emit}}
			}
		else component "fuel_tank_internal_d"
			{if not tagged "destroyed"
				{damage_report "fuel_tank_external_d" "fuel:fuel_tank_damaged"}
			}
			{if rand 0.8
				{burn fx "smoke_dead_norm" fake}
				{fire radius 4 time 1 heating 3}
				{call "_burn"}
				{if rand 0.8
					{spawn "ex_air_big"}
				}
				{delay 1 {crew_emit}}
				{delay 2 {crew_emit}}
				{delay 3 {crew_emit}}
			}
		else component "fuel_tank_external_a"
			{if not tagged "destroyed"
				{damage_report "fuel_tank_external_a" "fuel:fuel_tank_damaged"}
			}
			{if rand 0.8
				{burn fx "smoke_dead_norm" fake}
				{fire radius 6 time 2 heating 5}
				{if rand 0.8
					{spawn "ex_air_big"}
				}
			}
		else component "fuel_tank_external_b"
			{if not tagged "destroyed"
				{damage_report "fuel_tank_external_b" "fuel:fuel_tank_damaged"}
			}
			{if rand 0.8
				{burn fx "smoke_dead_norm" fake}
				{fire radius 6 time 2 heating 5}
				{if rand 0.8
					{spawn "ex_air_big"}
	;				{blastwave c4 2 r0 2 r1 4 position}
				}
			}
		else component "fuel_tank_external_c"
			{if not tagged "destroyed"
				{damage_report "fuel_tank_external_c" "fuel:fuel_tank_damaged"}
			}
			{if rand 0.8
				{burn fx "smoke_dead_norm" fake}
				{fire radius 6 time 2 heating 5}
				{if rand 0.8
					{spawn "ex_air_big"}
	;				{blastwave c4 2 r0 2 r1 4 position}
				}
			}
		else component "fuel_tank_external_d"
			{if not tagged "destroyed"
				{damage_report "fuel_tank_external_d" "fuel:fuel_tank_damaged"}
			}
			{if rand 0.8
				{burn fx "smoke_dead_norm" fake}
				{fire radius 6 time 2 heating 5}
				{if rand 0.8
					{spawn "ex_air_big"}
	;				{blastwave c4 2 r0 2 r1 4 position}
				}
			}
			;=========================
			;weapon and targeting systems
			;=========================
		else component "mgun"
			{if not tagged "destroyed"
				{damage_report "mgun" "mgun_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "mgun" 0}
			{tags add "mgun_damaged"}
		else component "mgun1"
			{if not tagged "destroyed"
				{damage_report "mgun1" "mgun:mgun_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "mgun1" 0}
			{tags add "mgun1_damaged"}
		else component "mgun2"
			{if not tagged "destroyed"
				{damage_report "mgun2" "mgun:mgun_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "mgun2" 0}
			{tags add "mgun2_damaged"}
		else component "mgun3"
			{if not tagged "destroyed"
				{damage_report "mgun3" "mgun:mgun_damaged"}
				}
			{tags add "mgun3_damaged"}
				{spawn "metal_hit_bul"}
			{weapon_work "mgun3" 0}
		else component "mgun4"
			{if not tagged "destroyed"
				{damage_report "mgun4" "mgun:mgun_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "mgun4" 0}
			{tags add "mgun4_damaged"}
		else component "mgun5"
			{if not tagged "destroyed"
				{damage_report "mgun5" "mgun:mgun_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "mgun5" 0}
			{tags add "mgun5_damaged"}
		else component "mgun6"
			{if not tagged "destroyed"
				{damage_report "mgun6" "mgun:mgun_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "mgun6" 0}
			{tags add "mgun6_damaged"}
		else component "mgun20"
			{if not tagged "destroyed"
				{damage_report "mgun20" "shtora:shtora_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "mgun20" 0}
			{tags add "mgun6_damaged"}
		else component "mgun21"
			{if not tagged "destroyed"
				{damage_report "mgun21" "shtora:shtora_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "mgun21" 0}
			{tags add "mgun6_damaged"}
		else component "gun1"
			{if not tagged "destroyed"
				{damage_report "gun1" "gun1_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "gun1" 0}
			{tags add "gun1_damaged"}
		else component "gun2"
			{if not tagged "destroyed"
				{damage_report "turret" "ptur_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "gun2" 0}
			{tags add "gun2_damaged"}
			{if ammo_tag_for_weapon "gun2" "ammo"
				{spawn "ex_air_big"}
				{fragments c4 6 r0 0.3 r1 0.5 position}
				{fragments c4 2 r0 3 r1 4 position}
			}
		else component "gun3"
			{if not tagged "destroyed"
				{damage_report "turret" "ptur_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "gun3" 0}
			{tags add "gun3_damaged"}
			{if ammo_tag_for_weapon "gun3" "ammo"
				{spawn "ex_air_big"}
				{fragments c4 6 r0 0.3 r1 0.5 position}
				{fragments c4 2 r0 3 r1 4 position}
			}
		else component "autoloader"
			{if not tagged "destroyed"
				{damage_report "autoloader" "autoloader_damaged"}
			}
			{tags add "autoloader_damaged"}
				{spawn "tank_die_particle" "body"}
		else component "turret_move_engine"
			{if not tagged "destroyed"
				{damage_report "turret_move_engine" "turret_move_engine_damaged"}
			}
				{spawn "metal_hit_bul"}
				{call "update_turret"}
			{tags add "turret_move_engine_damaged"}
		else component "turret_ring"
			{burn fx "smoke_dead_tank2" fake}
			{components "turret" break}
			{tags add "turret_ring_broken"}	
		else component "stabilizer"
			{if not tagged "destroyed"
				{damage_report "stabilizer" "stabilizer_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "gun" 0}

			{tags add "stabilizer_damaged"}
			{if not tagged "crit_system_destroyed"
				{tags add "crit_system_destroyed"}
			else
				{if not tagged "crit_system_destroyed2"
				   {tags add "crit_system_destroyed2"}
				else
					{components "body" break}
				}	  
			}
		else component "gunner_panel"
			{if not tagged "destroyed"
				{damage_report "gunner_panel" "gunner_panel_damaged"}
			}
				{spawn "metal_hit_bul"}
				{weapon_work "gun" 0}
			{tags add "gunner_panel_damaged"}
		else component "driver_triplex"		
			{if not tagged "destroyed"
				{damage_report "driver_triplex" "driver_triplex_damaged"}
			}		
				{tags add "driver_triplex_damaged"}
				{ani_play "visor2"}
				{components "visor2" break}
		else component "commander_triplex"
			{if not tagged "destroyed"
				{damage_report "commander_triplex" "commander_triplex_damaged"}
			}
				{tags add "commander_triplex_damaged"}
				{ani_play "visor1"}
				{components "visor1" break}
		else component "additional_triplex"
			{if not tagged "destroyed"
				{damage_report "additional_triplex" "additional_triplex:additional_triplex_damaged"}
			}
				{tags add "additional_triplex_damaged"}
				{ani_play "visor3"}
				{components "visor3" break}
		else component "additional_triplex1"
			{if not tagged "destroyed"
				{damage_report "additional_triplex1" "additional_triplex:additional_triplex_damaged"}
			}
				{tags add "additional_triplex1_damaged"}
				{ani_play "visor4"}
				{components "visor4" break}
		else component "additional_triplex2"
			{if not tagged "destroyed"
				{damage_report "additional_triplex2" "additional_triplex:additional_triplex_damaged"}
			}
				{tags add "additional_triplex2_damaged"}
				{ani_play "visor5"}
				{components "visor5" break}
		else component "additional_triplex3"
			{if not tagged "destroyed"
				{damage_report "additional_triplex3" "additional_triplex:additional_triplex_damaged"}
			}
				{tags add "additional_triplex3_damaged"}
				{ani_play "visor6"}
				{components "visor6" break}
		else component "additional_triplex4"
			{if not tagged "destroyed"
				{damage_report "additional_triplex4" "additional_triplex:additional_triplex_damaged"}
			}
				{tags add "additional_triplex4_damaged"}
				{ani_play "visor7"}
				{components "visor7" break}
		else component "additional_triplex5"
			{if not tagged "destroyed"
				{damage_report "additional_triplex5" "additional_triplex:additional_triplex_damaged"}
			}
				{tags add "additional_triplex5_damaged"}
				{ani_play "visor8"}
				{components "visor8" break}
		else component "shtora_visor"
			{if not tagged "destroyed"
				{damage_report "shtora_visor" "shtora:shtora_damaged"}
			}
				{tags add "shtora_visor_damaged"}
				{ani_play "shtora_visor"}
				{components "shtora_visor" break}
		else component "shtora_visor1"
			{if not tagged "destroyed"
				{damage_report "shtora_visor1" "shtora:shtora_damaged"}
			}
				{tags add "shtora_visor1_damaged"}
				{ani_play "shtora_visor1"}
				{components "shtora_visor1" break}
		else component "shtora_visor2"
			{if not tagged "destroyed"
				{damage_report "shtora_visor2" "shtora:shtora_damaged"}
			}
				{tags add "shtora_visor2_damaged"}
				{ani_play "shtora_visor2"}
				{components "shtora_visor2" break}
		else component "shtora_visor3"
			{if not tagged "destroyed"
				{damage_report "shtora_visor3" "shtora:shtora_damaged"}
			}
				{tags add "shtora_visor3_damaged"}
				{ani_play "shtora_visor3"}
				{components "shtora_visor3" break}
			;=========================
			;power supply
			;=========================
		else component "ppu"
			{if not tagged "destroyed"
				{damage_report "ppu" "ppu_damaged"}
			}
				{spawn "metal_hit_bul"}
			{tags add "ppu_damaged"}
			{call "update_turret"}
		else component "apu"
			{if not tagged "destroyed"
				{damage_report "apu" "apu_damaged"}
			}
				{spawn "metal_hit_bul"}
			{tags add "apu_damaged"}
			{call "update_power"}
			{delay 0.1 {call "update_turret"}}
			;=========================
			;other
			;=========================
		else component "hull_integrity"
			{if not tagged "destroyed"
				{damage_report "body" "hull_integrity_damaged"}
				{call "check_water_level"}
			}
			{tags add "hull_integrity_damaged"}
		}
; end of defines of "break" events
;=============================================
	}
;=============================================
;defines of "repair" events
	{on repair
		;=========================
		;mover parts and engine
		;=========================
	{if component "driver_panel"
		{tags remove "driver_panel_damaged"}
		{damage_report "driver_panel" "driver_panel_repaired"}
		{if tagged "crit_system_destroyed2"
		{tags remove "crit_system_destroyed2"}
		 else
		  {if tagged "crit_system_destroyed"
		   {tags remove "crit_system_destroyed"}
		  }
            ; else
		 ; {if tagged "crit_system_destroyed3"
		  ; {tags remove "crit_system_destroyed3"}
		  ;} 		  
		}
		{call "update_moveability"}

		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "ammo_storage_main" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}

		else component "transmission"
		{tags remove "transmission_damaged"}
		{tags remove "antifire_not_work"}
		{damage_report "transmission" "transmission_repaired"}
		{if tagged "crit_system_destroyed2"
		{tags remove "crit_system_destroyed2"}
		 else
		  {if tagged "crit_system_destroyed"
		   {tags remove "crit_system_destroyed"}
		  }
            ; else
		 ; {if tagged "crit_system_destroyed3"
		  ; {tags remove "crit_system_destroyed3"}
		  ;} 		  
		}
		{call "update_moveability"}

		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "ammo_storage_main" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "panel_engine_connectors"
		{tags remove "panel_engine_connectors_damaged"}
		{damage_report "panel_engine_connectors" "panel_engine_connectors_repaired"}
		{if tagged "crit_system_destroyed2"
		{tags remove "crit_system_destroyed2"}
		 else
		  {if tagged "crit_system_destroyed"
		   {tags remove "crit_system_destroyed"}
		  }
            ; else
		 ; {if tagged "crit_system_destroyed3"
		  ; {tags remove "crit_system_destroyed3"}
		  ;} 		  
		}
		{call "update_moveability"}

		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "ammo_storage_main" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "front_wheels"
		{tags remove "front_wheels_damaged"}
		{damage_report "front_wheels" "front_wheels_repaired"}
		{call "update_moveability"}

		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "ammo_storage_main" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}

		;=========================
		;weapon and targeting systems
		;=========================
	else component "autoloader"
		{damage_report "autoloader" "autoloader_repaired"}
		{tags remove "autoloader_damaged"}
	else component "mgun"
		{damage_report "mgun" "mgun_repaired"}
		{weapon_work "mgun" 1}
		{tags remove "mgun_damaged"}
	else component "mgun1"
		{damage_report "mgun1" "mgun:mgun_repaired"}
		{weapon_work "mgun1" 1}
		{tags remove "mgun1_damaged"}
	else component "mgun2"
		{damage_report "mgun2" "mgun:mgun_repaired"}
		{weapon_work "mgun2" 1}
		{tags remove "mgun2_damaged"}
	else component "mgun3"
		{damage_report "mgun3" "mgun:mgun_repaired"}
		{weapon_work "mgun3" 1}
		{tags remove "mgun3_damaged"}
	else component "mgun4"
		{damage_report "mgun4" "mgun:mgun_repaired"}
		{weapon_work "mgun4" 1}
		{tags remove "mgun4_damaged"}
	else component "mgun5"
		{damage_report "mgun5" "mgun:mgun_repaired"}
		{weapon_work "mgun5" 1}
		{tags remove "mgun5_damaged"}
	else component "mgun6"
		{damage_report "mgun6" "mgun:mgun_repaired"}
		{weapon_work "mgun6" 1}
		{tags remove "mgun6_damaged"}
	else component "mgun20"
		{damage_report "mgun20" "shtora:shtora_repaired"}
		{weapon_work "mgun20" 1}
	else component "mgun21"
		{damage_report "mgun21" "shtora:shtora_repaired"}
		{weapon_work "mgun21" 1}
	else component "gun1"
		{damage_report "gun1" "gun1_repaired"}
		{tags remove "gun1_damaged"}
		{weapon_work "gun1" 1}
	else component "gun2"
		{damage_report "turret" "ptur:ptur_repaired"}
		{tags remove "gun2_damaged"}
		{weapon_work "gun2" 1}
	else component "gun3"
		{damage_report "turret" "ptur:ptur_repaired"}
		{tags remove "gun3_damaged"}
		{weapon_work "gun3" 1}
	else component "turret_move_engine"
		{damage_report "turret_move_engine" "turret_move_engine_repaired"}
		{tags remove "turret_move_engine_damaged"}
		{call "update_turret"}
	else component "stabilizer"
		{damage_report "stabilizer" "stabilizer_repaired"}
		{tags remove "stabilizer_damaged"}
		{tags remove "antifire_not_work"}
	    {call "update_weaponry"}
	else component "gunner_panel"
		{damage_report "gunner_panel" "gunner_panel_repaired"}
		{tags remove "gunner_panel_damaged"}
	    {call "update_weaponry"}
	else component "driver_triplex"
		{damage_report "driver_triplex" "driver_triplex_repaired"}
		{tags remove "driver_triplex_damaged"}
		{ani_play "visor2" -1}{ani_play "visor90deg_2" -1}
		{call "update_power"}
	else component "commander_triplex"
		{damage_report "commander_triplex" "commander_triplex_repaired"}
		{tags remove "commander_triplex_damaged"}
		{ani_play "visor1" -1}{ani_play "visor90deg_1" -1}
		{call "update_power"}
	else component "additional_triplex"
		{damage_report "additional_triplex" "additional_triplex_repaired"}
		{tags remove "additional_triplex_damaged"}
		{ani_play "visor3" -1}{ani_play "visor90deg_3" -1}
		{call "update_power"}
	else component "additional_triplex1"
		{damage_report "additional_triplex1" "additional_triplex:additional_triplex_repaired"}
		{tags remove "additional_triplex1_damaged"}
		{ani_play "visor4" -1}{ani_play "visor90deg_4" -1}
		{call "update_power"}
	else component "additional_triplex2"
		{damage_report "additional_triplex1" "additional_triplex:additional_triplex_repaired"}
		{tags remove "additional_triplex2_damaged"}
		{ani_play "visor5" -1}{ani_play "visor90deg_5" -1}
		{call "update_power"}
	else component "additional_triplex3"
		{damage_report "additional_triplex1" "additional_triplex:additional_triplex_repaired"}
		{tags remove "additional_triplex3_damaged"}
		{ani_play "visor6" -1}{ani_play "visor90deg_6" -1}
		{call "update_power"}
	else component "additional_triplex4"
		{damage_report "additional_triplex1" "additional_triplex:additional_triplex_repaired"}
		{tags remove "additional_triplex4_damaged"}
		{ani_play "visor7" -1}{ani_play "visor90deg_7" -1}
		{call "update_power"}
	else component "additional_triplex5"
		{damage_report "additional_triplex1" "additional_triplex:additional_triplex_repaired"}
		{tags remove "additional_triplex5_damaged"}
		{ani_play "visor8" -1}{ani_play "visor90deg_8" -1}
		{call "update_power"}
	else component "shtora_visor"
		{damage_report "shtora_visor" "shtora:shtora_repaired"}
		{tags remove "shtora_visor_damaged"}
		{ani_play "shtora_visor" -1}
	else component "shtora_visor1"
		{damage_report "shtora_visor1" "shtora:shtora_repaired"}
		{tags remove "shtora_visor1_damaged"}
		{ani_play "shtora_visor1" -1}
	else component "shtora_visor2"
		{damage_report "shtora_visor2" "shtora:shtora_repaired"}
		{tags remove "shtora_visor2_damaged"}
		{ani_play "shtora_visor2" -1}
	else component "shtora_visor3"
		{damage_report "shtora_visor3" "shtora:shtora_repaired"}
		{tags remove "shtora_visor3_damaged"}
		{ani_play "shtora_visor3" -1}
		;=========================
		;power supply
		;=========================
	else component "ppu"
		{damage_report "ppu" "ppu_repaired"}
		{tags remove "ppu_damaged"}
		{tags remove "engine_cannot_start"}
		
		{call "update_power"}
		{call "update_turret"}
		{call "update_moveability"}

		{components "ammo_storage_mgun" repair}
		{components "ammo_storage_autocannon" repair}
		{components "ammo_storage_main" repair}
		{components "fuel_tank_internal_a" repair}
		{components "fuel_tank_internal_b" repair}
		{components "fuel_tank_internal_c" repair}
		{components "fuel_tank_internal_d" repair}
	else component "apu"
		{damage_report "apu" "apu_repaired"}
		{tags remove "apu_damaged"}
		{tags remove "engine_cannot_start"}
		{tags remove "antifire_not_work"}
		{call "update_power"}
	
		;=========================
		;other
		;=========================

	else component "hull_integrity"
		{damage_report "body" "hull_integrity_repaired"}
		{tags remove "hull_integrity_damaged"}
	}
; end of defines of "repair" events
;=============================================
	}
	{on "update_lights"
		{kill_delay "update_ammo_storage"}
		{delay 10 "update_ammo_storage"
			{if explosive_amount 10
				{if not work "ammo_storage_mgun" {components "ammo_storage_mgun" repair}}
				{if not work "ammo_storage_autocannon" {components "ammo_storage_autocannon" repair}}
				{if not work "ammo_storage_main" {components "ammo_storage_main" repair}}
			}
		}
	}
	{on "update_syst_on_spawn"
		{if not work "driver_panel" {chassis_work 0} {components "move_indicator" break}}
		{if not work "transmission" {chassis_work 0} {components "move_indicator" break}}
		{if not work "panel_engine_connectors" {chassis_work 0} {components "move_indicator" break}}
		{call "update_moveability"}
		{if not work "hull_integrity" {call "check_water_level"}}

		{if not work "turret_move_engine" {ik_enable "turret" 0}}
		{tags remove "contusion"}
		{tags remove "temp_no_power"}
		{set "already_blasted" 0}
				  {call "update_turret"}
				  {call "update_weaponry"}
				  {call "update_power"}
		{if not work "driver_triplex" {ani_play "visor2"} else tagged "blinding_laser"  {ani_play "visor2" -1}{ani_play "visor90deg_2" -1}}
		{if not work "commander_triplex"	{ani_play "visor1"}	 else tagged "blinding_laser" {ani_play "visor1" -1}{ani_play "visor90deg_1" -1}}
		{if not work "additional_triplex"	{ani_play "visor3"}	 else tagged "blinding_laser"  {ani_play "visor3" -1}{ani_play "visor90deg_3" -1}}
		{if not work "additional_triplex1"	{ani_play "visor4"}	 else tagged "blinding_laser"  {ani_play "visor4" -1}{ani_play "visor90deg_4" -1}}
		{if not work "additional_triplex2"	{ani_play "visor5"}	 else tagged "blinding_laser"  {ani_play "visor5" -1}{ani_play "visor90deg_5" -1}}
		{if not work "additional_triplex3"	{ani_play "visor6"}	 else tagged "blinding_laser"  {ani_play "visor6" -1}{ani_play "visor90deg_6" -1}}
		{if not work "additional_triplex4"	{ani_play "visor7"}	 else tagged "blinding_laser"  {ani_play "visor7" -1}{ani_play "visor90deg_7" -1}}
		{if not work "additional_triplex5"	{ani_play "visor8"}	 else tagged "blinding_laser"  {ani_play "visor8" -1}{ani_play "visor90deg_8" -1}}
		{tags remove "blinding_laser"}
		{if not work "shtora_visor"
			{ani_play "shtora_visor"}
		}
		{if not work "shtora_visor1"
			{ani_play "shtora_visor1"}
		}
		{if not work "shtora_visor2"
			{ani_play "shtora_visor2"}
		}
		{if not work "shtora_visor3"
			{ani_play "shtora_visor3"}
		}
	}
	;=============================================
;updates of tank state
;work of power sources - main and additional
	{on engine on overload
		{call "engine_on"}
	}
	{on "engine_on"
		{if not flag "engine_started"
		  {if not work "ppu"
			{tags add "engine_cannot_start"}
			{chassis_work 0} {components "move_indicator" break}
		  }
		}
		{set "engine_started" 1}
		{kill_delay "engine_stopped"}
		{kill_delay "engine_steam_stopped"}
		{stop_sound "engine_end"}
		{play_sound "engine" 1}
		{view start "engine_steam"}
		{call "update_power"}
		{call "update_turret"}
	}

	{on engine off overload
				{call "engine_off"}
	}
	{on "engine_off"
		{if not work "ppu"
			{delay 8 "engine_stopped"
				{stop_sound "engine"}
				{play_sound "engine_end"}
				{chassis_work 0} {components "move_indicator" break}
				{tags add "engine_cannot_start"}
				{set "engine_started" 0}
				{call "update_power"}
				{call "update_turret"}
			}
			{delay 16 "engine_steam_stopped"
				{view pause "engine_steam"}
			}
		else
			{tags remove "engine_cannot_start"}
			{delay 4 "engine_stopped"
				{stop_sound "engine"}
				{play_sound "engine_end"}
				{set "engine_started" 0}
				{call "update_power"}
				{call "update_turret"}
			}
			{delay 12 "engine_steam_stopped"
				{view pause "engine_steam"}
			}
		}
	}
	{on crew in {call "update_crew_vol"}}
	{on crew out {call "update_crew_vol"}}
	{on "update_crew_vol"
		(define "check_crew_place"
			{if crew_in_place "%name"	
				{volumes "%name_place" enable blast bullet}
				{if not work "%name_place" {components "%name_place" repair}}
			else {volumes "%name_place" disable blast bullet}
			}
		)
		("check_crew_place" name(driver))("check_crew_place" name(driver1))
		("check_crew_place" name(gunner))("check_crew_place" name(gunner1))	("check_crew_place" name(gunner2))
		("check_crew_place" name(charger)) ("check_crew_place" name(charger1))
		("check_crew_place" name(commander)) ("check_crew_place" name(commander1))
		("check_crew_place" name(seat1)) ("check_crew_place" name(seat2))
		("check_crew_place" name(seat3)) ("check_crew_place" name(seat4))
		("check_crew_place" name(seat5)) ("check_crew_place" name(seat6))
		("check_crew_place" name(seat7)) ("check_crew_place" name(seat8))
		("check_crew_place" name(seat9)) ("check_crew_place" name(seat10))
		("check_crew_place" name(seat11)) ("check_crew_place" name(seat12))
		("check_crew_place" name(seat13)) ("check_crew_place" name(seat14))
		("check_crew_place" name(seat15)) ("check_crew_place" name(seat16))
		("check_crew_place" name(seat17)) ("check_crew_place" name(seat18))
		("check_crew_place" name(seat19)) ("check_crew_place" name(seat20))
		("check_crew_place" name(seat21)) ("check_crew_place" name(seat22))
		("check_crew_place" name(seat23)) ("check_crew_place" name(seat24))
		("check_crew_place" name(seat25))
	}
	{on "update_moveability"
		{if work "transmission"
			{if work "body"
			 {if work "driver_panel"
				{if work "panel_engine_connectors"
					{if work "engine"
					  {if work "trackright"
						{if work "trackleft"
						   {if not flag "mover_damaged"
							{if not tagged "contusion"
								{chassis_work 1} {components "move_indicator" repair}
								{tags remove "chassis_brake"}
							}
						   }
						}
					   }
					}
				}
			  }
			}
		}
		{if not work "turret"
			{if tagged "chassis_brake"
				{call "check_burn_emit"}
				{delay 10 {crew_emit}}
				{delay 12 {crew_emit}}
				{delay 13 {crew_emit}}
			}
		}
		{call "_update_wheel_mover"}
		{if work "front_wheels"
			{if tagged "1_wheel_broken"
			else tagged "2_wheel_broken"
			else tagged "3_wheel_broken"
			else tagged "4_wheel_broken"
			else not work "front_wheels" {movement_limit slow}
			else tagged "cwts_normal" {movement_limit normal}		
			else tagged "cwts_heavy" {movement_limit slow}
			else {movement_limit fast}
			}
		}
	}
	{on "update_weaponry"
		{delay 0.1
			{call "update_mgun"}
			{call "update_mgun1"}
			{call "update_mgun2"}
			{call "update_mgun3"}
			{call "update_mgun4"}
			{call "update_mgun5"}
			{call "update_mgun6"}
			{call "update_mgun20"}
			{call "update_mgun21"}
			{call "update_other_smokeguns"}
			{call "update_gun"}
			{call "update_gun1"}
			{call "update_gun23"}
			{call "update_radar"}
			{call "update_cw_panorama"}
		}
	}
	(define "update_mgun"
		{on "update_%mgun" 
			{if work "%mgun" 
				{if not tagged "contusion" {weapon_work "%mgun" 1}
				else {weapon_work "%mgun" 0}}
			else {weapon_work "%mgun" 0}}
		}
	)
	(define "update_remote_mgun"
		{on "update_%mgun" overload 
			{if work "%mgun"
			   {if work "gunner_panel"
				{if not tagged "contusion" 
					{if not tagged "no_power" {weapon_work "%mgun" 1}
					else {weapon_work "%mgun" 0}
					}
				else {weapon_work "%mgun" 0}}
			   else {weapon_work "%mgun" 0}}
			else {weapon_work "%mgun" 0}}
		}
	)
	(define "update_shtora_smokegun"	;shtora, has own component
		{on "update_%mgun" 
			{if work "%mgun" 
				{if not tagged "no_power" {weapon_work "%mgun" 1}
				else {weapon_work "%mgun" 0}
				}
			else {weapon_work "%mgun" 0}
			}
		}
	)
	("update_mgun" mgun(mgun)) ("update_mgun" mgun(mgun1)) ("update_mgun" mgun(mgun2)) ("update_mgun" mgun(mgun3))
	("update_mgun" mgun(mgun4)) ("update_mgun" mgun(mgun5)) ("update_mgun" mgun(mgun6))
	("update_shtora_smokegun" mgun(mgun20)) ("update_shtora_smokegun" mgun(mgun21))
	{on "update_other_smokeguns" 
		{if not tagged "no_power" 
			{weapon_work "mgun15" 1}{weapon_work "mgun16" 1}{weapon_work "mgun17" 1}{weapon_work "mgun18" 1}
			{weapon_work "mgun19" 1}{weapon_work "mgun22" 1}
		else
			{weapon_work "mgun15" 0}{weapon_work "mgun16" 0}{weapon_work "mgun17" 0}{weapon_work "mgun18" 0}
			{weapon_work "mgun19" 0}{weapon_work "mgun22" 0}
		}
	}
	{on "update_gun"
		{if work "gun"
			 {if work "stabilizer"
			   {if work "gunner_panel"
				{if not flag "specability"
				  {if not tagged "contusion"
						{if not tagged "cw_autoloader_stuck"
							{weapon_work "gun" 1}
						else {weapon_work "gun" 0}}
				  else {weapon_work "gun" 0}}
				else {weapon_work "gun" 0}}
			   else {weapon_work "gun" 0}}
			 else {weapon_work "gun" 0}}
		else {weapon_work "gun" 0}}
	}
	{on "update_gun1"
		{if work "gun1"
			 {if work "stabilizer"
			  {if work "gunner_panel"
			   {if not tagged "contusion"
				{weapon_work "gun1" 1}
			   else {weapon_work "gun1" 0}}
			  else {weapon_work "gun1" 0}}
			 else {weapon_work "gun1" 0}}
		else {weapon_work "gun1" 0}}
	}


	{on "update_gun23"
		{if work "gun2"
		 {if work "gunner_panel"
		  {if not tagged "no_power"
			{if not flag "specability"
			 {if not tagged "contusion"
				{weapon_work "gun2" 1}
			 else {weapon_work "gun2" 0}}
			else {weapon_work "gun2" 0}}
		  else {weapon_work "gun2" 0}}
		 else {weapon_work "gun2" 0} {tags add "no_missile_control"}}
		else {weapon_work "gun2" 0} {tags add "no_missile_control"}}
		{if work "gun3"
		 {if work "gunner_panel"
		  {if not tagged "no_power"
			{if not flag "specability"
			 {if not tagged "contusion"
				{weapon_work "gun3" 1}
			 else {weapon_work "gun3" 0}}
			else {weapon_work "gun3" 0}}
		  else {weapon_work "gun3" 0}}
		 else {weapon_work "gun3" 0} {tags add "no_missile_control"}}
		else {weapon_work "gun3" 0} {tags add "no_missile_control"}}
	}
	{on "update_power"
		{tags remove "no_missile_control"}
		{if not work "engine"
			{tags add "no_power"}
			{components "power_indicator" break}
		else not work "body"
			{tags add "no_power"}
			{components "power_indicator" break}
		else tagged "engine_cannot_start"
			{tags add "no_power"}
			{components "power_indicator" break}
		else tagged "temp_no_power"
			{tags add "no_power"}
			{components "power_indicator" break}
		else tagged "cwfs_fuel_0"
		  {if not chassis "water"
			{tags add "no_power"}
			{components "power_indicator" break}
		  }
		else {tags remove "no_power"} {components "power_indicator" repair}
		}
		{call "update_weaponry"}
		{call "update_turret"}
	}
	{on "update_turret"		
		{if not work "turret"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else not work "body"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else not work "turret_move_engine"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else tagged "contusion"
			{ik_enable "turret" 0} {tags add "no_missile_control"}
		else
			{ik_enable "turret" 1}
		}
	}

	{on "diagnostics"
		{if not work "driver_panel"
			{damage_report "driver_panel" "driver_panel_damaged"}
		}
		{if not work "transmission"
			{damage_report "transmission" "transmission_damaged"}
		}
		{if not work "panel_engine_connectors"
			{damage_report "panel_engine_connectors" "panel_engine_connectors_damaged"}
		}
		{if not work "front_wheels"
			{damage_report "front_wheels" "front_wheels_damaged"}
		}
		{if not work "mgun"
			{damage_report "mgun" "mgun_damaged"}
		else not work "mgun1"
			{damage_report "mgun1" "mgun:mgun_damaged"}
		else not work "mgun2"
			{damage_report "mgun2" "mgun:mgun_damaged"}
		else not work "mgun3"
			{damage_report "mgun3" "mgun:mgun_damaged"}
		else not work "mgun4"
			{damage_report "mgun4" "mgun:mgun_damaged"}
		else not work "mgun5"
			{damage_report "mgun5" "mgun:mgun_damaged"}
		else not work "mgun6"
			{damage_report "mgun6" "mgun:mgun_damaged"}
		}
		{if not work "mgun20"
			{damage_report "mgun20" "shtora:shtora_damaged"}
		else not work "mgun21"
			{damage_report "mgun21" "shtora:shtora_damaged"}
		}
		{if not work "gun"
			{damage_report "gun" "gun_broken"}
		}
		{if not work "gun1"
			{damage_report "gun1" "gun1_damaged"}
		}
		{if not work "gun2"
			{damage_report "gun2" "ptur_damaged"}
		else not work "gun3"
			{damage_report "gun3" "ptur_damaged"}
		}
		{if not work "autoloader"
			{damage_report "autoloader" "autoloader_damaged"}
		}
		{if not work "turret_move_engine"
			{damage_report "turret_move_engine" "turret_move_engine_damaged"}
		}
		{if not work "stabilizer"
			{damage_report "stabilizer" "stabilizer_damaged"}
		}
		{if not work "gunner_panel"
			{damage_report "gunner_panel" "gunner_panel_damaged"}
		}
		{if not work "driver_triplex"		
			{damage_report "driver_triplex" "driver_triplex_damaged"}
		}
		{if not work "commander_triplex"
			{damage_report "commander_triplex" "commander_triplex_damaged"}
		}
		{if not work "additional_triplex"
			{damage_report "additional_triplex" "additional_triplex_damaged"}
		else not work "additional_triplex1"
			{damage_report "additional_triplex1" "additional_triplex:additional_triplex_damaged"}
		else not work "additional_triplex2"
			{damage_report "additional_triplex2" "additional_triplex:additional_triplex_damaged"}
		else not work "additional_triplex3"
			{damage_report "additional_triplex3" "additional_triplex:additional_triplex_damaged"}
		else not work "additional_triplex4"
			{damage_report "additional_triplex4" "additional_triplex:additional_triplex_damaged"}
		else not work "additional_triplex5"
			{damage_report "additional_triplex5" "additional_triplex:additional_triplex_damaged"}
		}
		{if not work "shtora_visor"
			{damage_report "shtora_visor" "shtora:shtora_damaged"}
		else not work "shtora_visor1"
			{damage_report "shtora_visor1" "shtora:shtora_damaged"}
		else not work "shtora_visor2"
			{damage_report "shtora_visor2" "shtora:shtora_damaged"}
		else not work "shtora_visor3"
			{damage_report "shtora_visor3" "shtora:shtora_damaged"}
		}
		{if not work "ppu"
			{damage_report "ppu" "ppu_damaged"}
		}
		{if not work "apu"
			{damage_report "apu" "apu_damaged"}
		}
		{if not work "hull_integrity"
			{damage_report "body" "hull_integrity_damaged"}
		}
		{if not work "body"
			{damage_report "body" "body_broken"}
		}
		{if not work "turret"
			{damage_report "turret" "turret_broken"}
		}
		{if not work "engine"
			{damage_report "engine" "engine_broken"}
		}
		{if not work "kaz_radar"
			{damage_report "kaz_radar" "kaz_radar_damaged"}
		else not work "kaz_radar1"
			{damage_report "kaz_radar1" "kaz_radar:kaz_radar_damaged"}
		else not work "kaz_radar2"
			{damage_report "kaz_radar2" "kaz_radar:kaz_radar_damaged"}
		else not work "kaz_radar3"
			{damage_report "kaz_radar3" "kaz_radar:kaz_radar_damaged"}
		else not work "kaz_radar4"
			{damage_report "kaz_radar4" "kaz_radar:kaz_radar_damaged"}
		else not work "kaz_radar5"
			{damage_report "kaz_radar5" "kaz_radar:kaz_radar_damaged"}
		}
		{if not work "trophy_mortar_l"
			{damage_report "trophy_mortar_l" "kaz_mortar:kaz_mortar_damaged"}
		else not work "trophy_mortar_r"
			{damage_report "trophy_mortar_r" "kaz_mortar:kaz_mortar_damaged"}
		}
		{if not work "trackright"
			{damage_report "trackright" "track_injured"}
		else not work "trackleft"
			{damage_report "trackleft" "track_injured"}
		}
		{if not work "wheelleft1"
			{damage_report "wheelleft1" "wheels_damaged"}
		else not work "wheelright1"
			{damage_report "wheelright1" "wheels_damaged"}
		else not work "wheelleft2"
			{damage_report "wheelright2" "wheels_damaged"}
		else not work "wheelright2"
			{damage_report "wheelright2" "wheels_damaged"}
		else not work "wheelleft3"
			{damage_report "wheelright3" "wheels_damaged"}
		else not work "wheelright3"
			{damage_report "wheelright3" "wheels_damaged"}
		else not work "wheelleft4"
			{damage_report "wheelright4" "wheels_damaged"}
		else not work "wheelright4"
			{damage_report "wheelright4" "wheels_damaged"}
		}
	}
}
(include "cwfs_fuel.inc")