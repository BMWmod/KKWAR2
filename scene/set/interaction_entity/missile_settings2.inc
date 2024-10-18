;Тут происходит выбор боеприпаса, если есть несколько вариантов. 
;Просто пишите по аналогии, заменяя название бп и номера форесайтов с учетом всех носителей этой ракеты.
;Учтите, что для работы некоторых ракет нужно электропитание на пусковой в момент пуска
;Если пусковая стреляет только одним типом ракет - в "proj_probe" ничего не пишется
{"proj_probe"
	{on spawn
		{delay 0.2 
			{impulse up -555 com} 
			{delay 5.0 {delete}}
		}
	}
	{on bullet_hit overload
	       {impulse up 0.01 com}
	       {gravity 0.01}
	       {volumes "body" disable all}
	       {if stuff "bullet125_RUS rok ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "reflex_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "reflex_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "9m111 ammo"
			{if tagged "Foresight6" {with_effector {delay 0.03 {spawn "9k111_carrier" "Foresight6" x} } {with_effector}}
			else tagged "Foresight" {with_effector {delay 0.03 {spawn "9k111_carrier" "Foresight" x} } {with_effector}}
			else tagged "Foresight1" {with_effector {delay 0.03 {spawn "9k111_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9k111_carrier" "Foresight2" x} } {with_effector}}
			}
			else stuff "9m111m ammo"
			{if tagged "Foresight6" {with_effector {delay 0.03 {spawn "9k111m_carrier" "Foresight6" x} } {with_effector}}
			else tagged "Foresight" {with_effector {delay 0.03 {spawn "9k111m_carrier" "Foresight" x} } {with_effector}}
			else tagged "Foresight1" {with_effector {delay 0.03 {spawn "9k111m_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9k111m_carrier" "Foresight2" x} } {with_effector}}
			}
	       else stuff "9m113 ammo"
			{if tagged "Foresight6" {with_effector {delay 0.03 {spawn "9k113_carrier" "Foresight6" x} } {with_effector}}
			else tagged "Foresight" {with_effector {delay 0.03 {spawn "9k113_carrier" "Foresight" x} } {with_effector}}
			else tagged "Foresight1" {with_effector {delay 0.03 {spawn "9k113_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9k113_carrier" "Foresight2" x} } {with_effector}}
			}
	       else stuff "9m113m ammo"
			{if tagged "Foresight6" {with_effector {delay 0.03 {spawn "9k113m_carrier" "Foresight6" x} } {with_effector}}
			else tagged "Foresight" {with_effector {delay 0.03 {spawn "9k113m_carrier" "Foresight" x} } {with_effector}}
			else tagged "Foresight1" {with_effector {delay 0.03 {spawn "9k113m_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9k113m_carrier" "Foresight2" x} } {with_effector}}
			}
			else stuff "9m113m1 ammo"
			{if tagged "Foresight6" {with_effector {delay 0.03 {spawn "9k113m1_carrier" "Foresight6" x} } {with_effector}}
			else tagged "Foresight" {with_effector {delay 0.03 {spawn "9k113m1_carrier" "Foresight" x} } {with_effector}}
			else tagged "Foresight1" {with_effector {delay 0.03 {spawn "9k113m1_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9k113m1_carrier" "Foresight2" x} } {with_effector}}
			}
			else stuff "hj73c ammo"
			{if tagged "ShooterR_00" {with_effector {delay 0.03 {spawn "hj73c_carrier" "ShooterR_00" x} } {with_effector}}
			else tagged "ShooterR_01" {with_effector {delay 0.03 {spawn "hj73c_carrier" "ShooterR_01" x} } {with_effector}}
			else tagged "foresight2" {with_effector {delay 0.03 {spawn "hj73c_carrier" "foresight2" x} } {with_effector}}
			else tagged "foresight4" {with_effector {delay 0.03 {spawn "hj73c_carrier" "foresight4" x} } {with_effector}}
			else tagged "foresight5" {with_effector {delay 0.03 {spawn "hj73c_carrier" "foresight5" x} } {with_effector}}
			else tagged "foresight6" {with_effector {delay 0.03 {spawn "hj73c_carrier" "foresight6" x} } {with_effector}}
			else tagged "foresight1_spawn" {with_effector {delay 0.03 {spawn "hj73c_carrier" "foresight1_spawn" x} } {with_effector}}
			}
			else stuff "hj-10 hj-10b ammo"
			{if tagged "Shooter00" {with_effector {delay 0.03 {spawn "red_arrow_10b_carrier" "Shooter00" x} } {with_effector}}
			else tagged "Shooter01" {with_effector {delay 0.03 {spawn "red_arrow_10b_carrier" "Shooter01" x} } {with_effector}}
			else tagged "Shooter02" {with_effector {delay 0.03 {spawn "red_arrow_10b_carrier" "Shooter02" x} } {with_effector}}
			else tagged "Shooter03" {with_effector {delay 0.03 {spawn "red_arrow_10b_carrier" "Shooter03" x} } {with_effector}}
			else tagged "Shooter04" {with_effector {delay 0.03 {spawn "red_arrow_10b_carrier" "Shooter04" x} } {with_effector}}
			else tagged "Shooter05" {with_effector {delay 0.03 {spawn "red_arrow_10b_carrier" "Shooter05" x} } {with_effector}}
			else tagged "Shooter06" {with_effector {delay 0.03 {spawn "red_arrow_10b_carrier" "Shooter06" x} } {with_effector}}
			else tagged "Shooter07" {with_effector {delay 0.03 {spawn "red_arrow_10b_carrier" "Shooter07" x} } {with_effector}}
			}

	       else stuff "9k115-2 cm_e ammo"
			 {with_effector {delay 0.03 {spawn "9k115-1_cm_carrier" "Foresight1" x} } {with_effector}} ;чтобы в землю не бился.
	       else stuff "9k115-2 cm ammo"
			 {with_effector {delay 0.03 {spawn "9k115-2_cm_carrier" "Foresight1" x} } {with_effector}} ;чтобы в землю не бился.
	       else stuff "bullet100a_RUS rok ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "9m117_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "9m117_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "bullet100a_RUS_h rok ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "9m117m_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "9m117m_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "bullet115_RUS rok ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "9m117_115_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "9m117_115_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "bullet105_cn rok ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "9m117cn_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "9m117cn_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "bullet100_cn_rapira rok ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "9m117cn100_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "9m117cn100_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "bullet125_h_rus rok ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "9m119m1_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "9m119m1_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "bullet125_m_rus rok ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "9m119m_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "9m119m_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "tow_rock ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "tow_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "tow_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "tow_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "tow_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "tow2b ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "tow2b_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "tow2b_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "tow2b_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "tow2b_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "tow2d ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "tow2d_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "tow2d_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "tow2d_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "tow2d_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "tow2e ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "tow2e_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "tow2e_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "tow2e_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "tow2e_carrier" "Foresight6" x} } {with_effector}}
			}
			else stuff "tow2_fg ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "tow2_fg_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "tow2_fg_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "tow2_fg_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "tow2_fg_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "hj8e ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "hj8e_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "hj8e_carrier" "Foresight2" x} } {with_effector}}
			}
	       else stuff "hj8h ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "hj8h_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "hj8h_carrier" "Foresight2" x} } {with_effector}}
			}
	       else stuff "hj8f ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "hj8f_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "hj8f_carrier" "Foresight2" x} } {with_effector}}
			}
			else stuff "milan_rock ammo"
			{if tagged "Foresight6" {with_effector {delay 0.03 {spawn "milan_rock_carrier" "Foresight6" x} } {with_effector}}
			else tagged "foresight1" {with_effector {delay 0.03 {spawn "milan_rock_carrier" "foresight1" x} } {with_effector}}
			else tagged "foresight1_spawn" {with_effector {delay 0.03 {spawn "milan_rock_carrier" "foresight1_spawn" x} } {with_effector}}
			}
	       else stuff "milan-er ammo"
			{if tagged "Foresight6" {with_effector {delay 0.03 {spawn "milan-er_carrier" "Foresight6" x} } {with_effector}}
			else tagged "foresight1" {with_effector {delay 0.03 {spawn "milan_rock_carrier" "foresight1" x} } {with_effector}}
			else tagged "foresight1_spawn" {with_effector {delay 0.03 {spawn "milan-er_carrier" "foresight1_spawn" x} } {with_effector}}
			}
			 else stuff "spike-er2 ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "spike-er2_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "spike-er2_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "spike-er2_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "spike-er2_carrier" "Foresight6" x} } {with_effector}}
			}
			 else stuff "spike-er ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "spike-er_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "spike-er_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "spike-er_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "spike-er_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "9m133 cm_e ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "9m133_cm_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9m133_cm_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "9m133_cm_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight4" {with_effector {delay 0.03 {spawn "9m133_cm_carrier" "Foresight4" x} } {with_effector}}
			else tagged "Foresight5" {with_effector {delay 0.03 {spawn "9m133_cm_carrier" "Foresight5" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "9m133_cm_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "9m133 cm ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "9m133_1_cm_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9m133_1_cm_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "9m133_1_cm_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight4" {with_effector {delay 0.03 {spawn "9m133_1_cm_carrier" "Foresight4" x} } {with_effector}}
			else tagged "Foresight5" {with_effector {delay 0.03 {spawn "9m133_1_cm_carrier" "Foresight5" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "9m133_1_cm_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "9m133 fg ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "9m133_fg_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9m133_fg_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "9m133_fg_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight4" {with_effector {delay 0.03 {spawn "9m133_fg_carrier" "Foresight4" x} } {with_effector}}
			else tagged "Foresight5" {with_effector {delay 0.03 {spawn "9m133_fg_carrier" "Foresight5" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "9m133_fg_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "9m133 tb ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "9m133_tb_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9m133_tb_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "9m133_tb_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight4" {with_effector {delay 0.03 {spawn "9m133_tb_carrier" "Foresight4" x} } {with_effector}}
			else tagged "Foresight5" {with_effector {delay 0.03 {spawn "9m133_tb_carrier" "Foresight5" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "9m133_tb_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "shershen cm ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "shershen_ammo_cm_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "shershen_ammo_cm_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "shershen_ammo_cm_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "shershen fg ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "shershen_ammo_fg_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "shershen_ammo_fg_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight6" {with_effector {delay 0.03 {spawn "shershen_ammo_fg_carrier" "Foresight6" x} } {with_effector}}
			}
	       else stuff "lahat ammo" {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "lahat_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "lahat_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "spike_nlos cm ammo"
		    {if tagged "shooter00" {with_effector {delay 0.03 
				{if tagged "no_power"  {spawn "spike_nlos_carrier" "shooter00" x {tags add "no_power"}}
				else  {spawn "spike_nlos_carrier" "shooter00" x}}}{with_effector} }
			else tagged "shooter01" {with_effector {delay 0.03 
				{if tagged "no_power"  {spawn "spike_nlos_carrier" "shooter01" x {tags add "no_power"}}
				else  {spawn "spike_nlos_carrier" "shooter01" x}}}{with_effector} }
			else tagged "shooter02" {with_effector {delay 0.03 
				{if tagged "no_power"  {spawn "spike_nlos_carrier" "shooter02" x {tags add "no_power"}}
				else  {spawn "spike_nlos_carrier" "shooter02" x}}}{with_effector} }
			else tagged "shooter03" {with_effector {delay 0.03 
				{if tagged "no_power"  {spawn "spike_nlos_carrier" "shooter03" x {tags add "no_power"}}
				else  {spawn "spike_nlos_carrier" "shooter03" x}}}{with_effector} }
			else tagged "shooter_r00" {with_effector {delay 0.03 {spawn "spike_nlos_carrier" "shooter_r00" x} } {with_effector}}
			else tagged "shooter_r01" {with_effector {delay 0.03 {spawn "spike_nlos_carrier" "shooter_r01" x} } {with_effector}}
            else tagged "shooter_r02" {with_effector {delay 0.03 {spawn "spike_nlos_carrier" "shooter_r02" x} } {with_effector}}
			else tagged "shooter_r03" {with_effector {delay 0.03 {spawn "spike_nlos_carrier" "shooter_r03" x} } {with_effector}}
			else tagged "shooter_l00" {with_effector {delay 0.03 {spawn "spike_nlos_carrier" "shooter_l00" x} } {with_effector}}
			else tagged "shooter_l01" {with_effector {delay 0.03 {spawn "spike_nlos_carrier" "shooter_l01" x} } {with_effector}}
            else tagged "shooter_l02" {with_effector {delay 0.03 {spawn "spike_nlos_carrier" "shooter_l02" x} } {with_effector}}
			else tagged "shooter_l03" {with_effector {delay 0.03 {spawn "spike_nlos_carrier" "shooter_l03" x} } {with_effector}}
			}
	       else stuff "spike_nlos fg ammo"
		    {if tagged "shooter00" {with_effector {delay 0.03 
				{if tagged "no_power"  {spawn "spike_nlos_fg_carrier" "shooter00" x {tags add "no_power"}}
				else  {spawn "spike_nlos_fg_carrier" "shooter00" x}}}{with_effector} }
			else tagged "shooter01" {with_effector {delay 0.03 
				{if tagged "no_power"  {spawn "spike_nlos_fg_carrier" "shooter01" x {tags add "no_power"}}
				else  {spawn "spike_nlos_fg_carrier" "shooter01" x}}}{with_effector} }
			else tagged "shooter02" {with_effector {delay 0.03 
				{if tagged "no_power"  {spawn "spike_nlos_fg_carrier" "shooter02" x {tags add "no_power"}}
				else  {spawn "spike_nlos_fg_carrier" "shooter02" x}}}{with_effector} }
			else tagged "shooter03" {with_effector {delay 0.03 
				{if tagged "no_power"  {spawn "spike_nlos_fg_carrier" "shooter03" x {tags add "no_power"}}
				else  {spawn "spike_nlos_fg_carrier" "shooter03" x}}}{with_effector} }
			else tagged "shooter_r00" {with_effector {delay 0.03 {spawn "spike_nlos_fg_carrier" "shooter_r00" x} } {with_effector}}
			else tagged "shooter_r01" {with_effector {delay 0.03 {spawn "spike_nlos_fg_carrier" "shooter_r01" x} } {with_effector}}
            else tagged "shooter_r02" {with_effector {delay 0.03 {spawn "spike_nlos_fg_carrier" "shooter_r02" x} } {with_effector}}
			else tagged "shooter_r03" {with_effector {delay 0.03 {spawn "spike_nlos_fg_carrier" "shooter_r03" x} } {with_effector}}
			else tagged "shooter_l00" {with_effector {delay 0.03 {spawn "spike_nlos_fg_carrier" "shooter_l00" x} } {with_effector}}
			else tagged "shooter_l01" {with_effector {delay 0.03 {spawn "spike_nlos_fg_carrier" "shooter_l01" x} } {with_effector}}
            else tagged "shooter_l02" {with_effector {delay 0.03 {spawn "spike_nlos_fg_carrier" "shooter_l02" x} } {with_effector}}
			else tagged "shooter_l03" {with_effector {delay 0.03 {spawn "spike_nlos_fg_carrier" "shooter_l03" x} } {with_effector}}
			}
	       else stuff "agm-114 k ammo"
			{if tagged "Foresight2" {with_effector {delay 0.03 {spawn "agm-114k_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "agm-114k_carrier" "Foresight3" x} } {with_effector}}
			else tagged "hellfire_shooter_00" {with_effector {delay 0.03 {spawn "agm-114k_carrier" "hellfire_shooter_00" x} } {with_effector}}
			else tagged "hellfire_shooter_01" {with_effector {delay 0.03 {spawn "agm-114k_carrier" "hellfire_shooter_01" x} } {with_effector}}
			else tagged "hellfire_shooter_02" {with_effector {delay 0.03 {spawn "agm-114k_carrier" "hellfire_shooter_02" x} } {with_effector}}
			else tagged "hellfire_shooter_03" {with_effector {delay 0.03 {spawn "agm-114k_carrier" "hellfire_shooter_03" x} } {with_effector}}
			else tagged "shooterl00" {with_effector {delay 0.03 {spawn "agm-114k_carrier" "shooterl00" x} } {with_effector}}
			else tagged "shooterl01" {with_effector {delay 0.03 {spawn "agm-114k_carrier" "shooterl01" x} } {with_effector}}
			}
	       else stuff "agm-114 k2 ammo"
			{if tagged "Foresight2" {with_effector {delay 0.03 {spawn "agm-114k2_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "agm-114k2_carrier" "Foresight3" x} } {with_effector}}
			else tagged "hellfire_shooter_00" {with_effector {delay 0.03 {spawn "agm-114k2_carrier" "hellfire_shooter_00" x} } {with_effector}}
			else tagged "hellfire_shooter_01" {with_effector {delay 0.03 {spawn "agm-114k2_carrier" "hellfire_shooter_01" x} } {with_effector}}
			else tagged "hellfire_shooter_02" {with_effector {delay 0.03 {spawn "agm-114k2_carrier" "hellfire_shooter_02" x} } {with_effector}}
			else tagged "hellfire_shooter_03" {with_effector {delay 0.03 {spawn "agm-114k2_carrier" "hellfire_shooter_03" x} } {with_effector}}
			else tagged "shooterl00" {with_effector {delay 0.03 {spawn "agm-114k2_carrier" "shooterl00" x} } {with_effector}}
			else tagged "shooterl01" {with_effector {delay 0.03 {spawn "agm-114k2_carrier" "shooterl01" x} } {with_effector}}
			}
	       else stuff "agm-114 l ammo"
			{if tagged "Foresight2" {with_effector {delay 0.03 {spawn "agm-114l_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "agm-114l_carrier" "Foresight3" x} } {with_effector}}
			else tagged "hellfire_shooter_00" {with_effector {delay 0.03 {spawn "agm-114l_carrier" "hellfire_shooter_00" x} } {with_effector}}
			else tagged "hellfire_shooter_01" {with_effector {delay 0.03 {spawn "agm-114l_carrier" "hellfire_shooter_01" x} } {with_effector}}
			else tagged "hellfire_shooter_02" {with_effector {delay 0.03 {spawn "agm-114l_carrier" "hellfire_shooter_02" x} } {with_effector}}
			else tagged "hellfire_shooter_03" {with_effector {delay 0.03 {spawn "agm-114l_carrier" "hellfire_shooter_03" x} } {with_effector}}
			else tagged "shooterl00" {with_effector {delay 0.03 {spawn "agm-114l_carrier" "shooterl00" x} } {with_effector}}
			else tagged "shooterl01" {with_effector {delay 0.03 {spawn "agm-114l_carrier" "shooterl01" x} } {with_effector}}
			}
	       else stuff "agm-114 n ammo"
			{if tagged "Foresight2" {with_effector {delay 0.03 {spawn "agm-114n_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "agm-114n_carrier" "Foresight3" x} } {with_effector}}
			else tagged "hellfire_shooter_00" {with_effector {delay 0.03 {spawn "agm-114n_carrier" "hellfire_shooter_00" x} } {with_effector}}
			else tagged "hellfire_shooter_01" {with_effector {delay 0.03 {spawn "agm-114n_carrier" "hellfire_shooter_01" x} } {with_effector}}
			else tagged "hellfire_shooter_02" {with_effector {delay 0.03 {spawn "agm-114n_carrier" "hellfire_shooter_02" x} } {with_effector}}
			else tagged "hellfire_shooter_03" {with_effector {delay 0.03 {spawn "agm-114n_carrier" "hellfire_shooter_03" x} } {with_effector}}
			else tagged "shooterl00" {with_effector {delay 0.03 {spawn "agm-114n_carrier" "shooterl00" x} } {with_effector}}
			else tagged "shooterl01" {with_effector {delay 0.03 {spawn "agm-114n_carrier" "shooterl01" x} } {with_effector}}
			}
	       else stuff "agm-114 r ammo"
			{if tagged "Foresight2" {with_effector {delay 0.03 {spawn "agm-114r_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "agm-114r_carrier" "Foresight3" x} } {with_effector}}
			else tagged "hellfire_shooter_00" {with_effector {delay 0.03 {spawn "agm-114r_carrier" "hellfire_shooter_00" x} } {with_effector}}
			else tagged "hellfire_shooter_01" {with_effector {delay 0.03 {spawn "agm-114r_carrier" "hellfire_shooter_01" x} } {with_effector}}
			else tagged "hellfire_shooter_02" {with_effector {delay 0.03 {spawn "agm-114r_carrier" "hellfire_shooter_02" x} } {with_effector}}
			else tagged "hellfire_shooter_03" {with_effector {delay 0.03 {spawn "agm-114r_carrier" "hellfire_shooter_03" x} } {with_effector}}
			else tagged "shooterl00" {with_effector {delay 0.03 {spawn "agm-114r_carrier" "shooterl00" x} } {with_effector}}
			else tagged "shooterl01" {with_effector {delay 0.03 {spawn "agm-114r_carrier" "shooterl01" x} } {with_effector}}
			}
		else stuff "brimstone ammo"
			{if tagged "Foresight2" {with_effector {delay 0.03 {spawn "brimstone_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "brimstone_carrier" "Foresight3" x} } {with_effector}}
			else tagged "brimstone_shooter_00" {with_effector {delay 0.03 {spawn "brimstone_carrier" "brimstone_shooter_00" x} } {with_effector}}
			else tagged "brimstone_shooter_01" {with_effector {delay 0.03 {spawn "brimstone_carrier" "brimstone_shooter_01" x} } {with_effector}}
			else tagged "brimstone_shooter_02" {with_effector {delay 0.03 {spawn "brimstone_carrier" "brimstone_shooter_02" x} } {with_effector}}
			else tagged "brimstone_shooter_03" {with_effector {delay 0.03 {spawn "brimstone_carrier" "brimstone_shooter_03" x} } {with_effector}}
			}
	       else stuff "trigat ammo"
			{if tagged "Foresight2" {with_effector {delay 0.03 {spawn "trigat_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "trigat_carrier" "Foresight3" x} } {with_effector}}
			}
	       else stuff "akd-10 ammo"
			{if tagged "Foresight2" {with_effector {delay 0.03 {spawn "akd-10_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "akd-10_carrier" "Foresight3" x} } {with_effector}}
			}
	       else stuff "strela10 9m37 ammo"
			{if tagged "shooter00" {with_effector {delay 0.03 {spawn "9k37_carrier" "shooter00" x} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 0.03 {spawn "9k37_carrier" "shooter01" x} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 0.03 {spawn "9k37_carrier" "shooter02" x} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 0.03 {spawn "9k37_carrier" "shooter03" x} } {with_effector}}
			}
	       else stuff "strela10 9m333 ammo"
			{if tagged "shooter00" {with_effector {delay 0.03 {spawn "9k333_carrier" "shooter00" x} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 0.03 {spawn "9k333_carrier" "shooter01" x} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 0.03 {spawn "9k333_carrier" "shooter02" x} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 0.03 {spawn "9k333_carrier" "shooter03" x} } {with_effector}}
			}
	       else stuff "9m38 buk ammo"
			{if tagged "shooter00" {with_effector {delay 0.03 {spawn "9m38_carrier" "shooter00" x} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 0.03 {spawn "9m38_carrier" "shooter01" x} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 0.03 {spawn "9m38_carrier" "shooter02" x} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 0.03 {spawn "9m38_carrier" "shooter03" x} } {with_effector}}
			else {with_effector {delay 0.03 {spawn "9m38_carrier" "Foresight2" x} } {with_effector}}
			}
	       else stuff "9m317 buk ammo"
			{if tagged "shooter00" {with_effector {delay 0.03 {spawn "9m317_carrier" "shooter00" x} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 0.03 {spawn "9m317_carrier" "shooter01" x} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 0.03 {spawn "9m317_carrier" "shooter02" x} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 0.03 {spawn "9m317_carrier" "shooter03" x} } {with_effector}}
			else {with_effector {delay 0.03 {spawn "9m317_carrier" "Foresight2" x} } {with_effector}}
			}
	       else stuff "hq16 hq16a ammo"
			{if tagged "shooter00" {with_effector {delay 1.15 {spawn "hq16a_missile_carrier" "shooter00" x} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 1.15 {spawn "hq16a_missile_carrier" "shooter01" x} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 1.15 {spawn "hq16a_missile_carrier" "shooter02" x} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 1.15 {spawn "hq16a_missile_carrier" "shooter03" x} } {with_effector}}
			else tagged "shooter04" {with_effector {delay 1.15 {spawn "hq16a_missile_carrier" "shooter04" x} } {with_effector}}
			else tagged "shooter05" {with_effector {delay 1.15 {spawn "hq16a_missile_carrier" "shooter05" x} } {with_effector}}
			else {with_effector {delay 1.15 {spawn "hq16a_missile_carrier" "Foresight1" x} } {with_effector}}
			}
	       else stuff "hq16 hq16b ammo"
			{if tagged "shooter00" {with_effector {delay 1.15 {spawn "hq16b_missile_carrier" "shooter00" x} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 1.15 {spawn "hq16b_missile_carrier" "shooter01" x} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 1.15 {spawn "hq16b_missile_carrier" "shooter02" x} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 1.15 {spawn "hq16b_missile_carrier" "shooter03" x} } {with_effector}}
			else tagged "shooter04" {with_effector {delay 1.15 {spawn "hq16b_missile_carrier" "shooter04" x} } {with_effector}}
			else tagged "shooter05" {with_effector {delay 1.15 {spawn "hq16b_missile_carrier" "shooter05" x} } {with_effector}}
			else {with_effector {delay 1.15 {spawn "hq16b_missile_carrier" "Foresight1" x} } {with_effector}}
			}
		   else stuff "fgm148e"
			{if tagged "Foresight2"
		   		{with_effector {delay 0.03 {spawn "proj_actorprobe" "Foresight2"   x {spawn "jav_rock_carrier" "missile_point15"   x}} } {with_effector}}
			else
				{with_effector {delay 0.03 {spawn "proj_actorprobe" "Foresight3"   x {spawn "jav_rock_carrier" "missile_point15"   x}} } {with_effector}}
			}
		   else stuff "fgm148f"
			{if tagged "Foresight2"
				{with_effector {delay 0.03 {spawn "proj_actorprobe" "Foresight2"   x {spawn "javf_rock_carrier" "missile_point15"   x}} } {with_effector}}
			else
				{with_effector {delay 0.03 {spawn "proj_actorprobe" "Foresight3"   x {spawn "javf_rock_carrier" "missile_point15"   x}} } {with_effector}}
			}
	       else stuff "9m114m fg ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "9m114f_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9m114f_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "9m114f_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight4" {with_effector {delay 0.03 {spawn "9m114f_carrier" "Foresight4" x} } {with_effector}}
			}
	       else stuff "9m114m cm ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "9m114m_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9m114m_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "9m114m_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight4" {with_effector {delay 0.03 {spawn "9m114m_carrier" "Foresight4" x} } {with_effector}}
			}
	       else stuff "9m120 fg ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "9m120f_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9m120f_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "9m120f_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight4" {with_effector {delay 0.03 {spawn "9m120f_carrier" "Foresight4" x} } {with_effector}}
			else tagged "shooter_ataka00" {with_effector {delay 0.03 {spawn "9m120f_carrier" "shooter_ataka00" x} } {with_effector}}
			else tagged "shooter_ataka01" {with_effector {delay 0.03 {spawn "9m120f_carrier" "shooter_ataka01" x} } {with_effector}}
			else tagged "shooter_ataka02" {with_effector {delay 0.03 {spawn "9m120f_carrier" "shooter_ataka02" x} } {with_effector}}
			else tagged "shooter_ataka03" {with_effector {delay 0.03 {spawn "9m120f_carrier" "shooter_ataka03" x} } {with_effector}}
			}
	       else stuff "9m120 cm ammo"
			{if tagged "Foresight1" {with_effector {delay 0.03 {spawn "9m120m_carrier" "Foresight1" x} } {with_effector}}
			else tagged "Foresight2" {with_effector {delay 0.03 {spawn "9m120m_carrier" "Foresight2" x} } {with_effector}}
			else tagged "Foresight3" {with_effector {delay 0.03 {spawn "9m120m_carrier" "Foresight3" x} } {with_effector}}
			else tagged "Foresight4" {with_effector {delay 0.03 {spawn "9m120m_carrier" "Foresight4" x} } {with_effector}}
			else tagged "shooter_ataka00" {with_effector {delay 0.03 {spawn "9m120m_carrier" "shooter_ataka00" x} } {with_effector}}
			else tagged "shooter_ataka01" {with_effector {delay 0.03 {spawn "9m120m_carrier" "shooter_ataka01" x} } {with_effector}}
			else tagged "shooter_ataka02" {with_effector {delay 0.03 {spawn "9m120m_carrier" "shooter_ataka02" x} } {with_effector}}
			else tagged "shooter_ataka03" {with_effector {delay 0.03 {spawn "9m120m_carrier" "shooter_ataka03" x} } {with_effector}}
			}
	       else stuff "sm_2er_blockiv aegis ammo"
			 {with_effector {delay 0.03 {call "launch_sm_2"} } {with_effector}}
	       else stuff "tomahawk aegis ammo"
			 {with_effector {delay 0.03 {call "launch_tomahawk"} } {with_effector}}
	       else stuff "tur_kobra ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "tur_kobra_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "tur_kobra_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "tur_kombat ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "tur_kombat_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "tur_kombat_carrier" "Foresight1" x}}}{with_effector}}
	       else stuff "53_65k_torpedo"
			{if tagged "shooter00" {with_effector {delay 0.1 {spawn "53_65k_torpedo_spawner" "shooter_000" x no_normal no_position} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 0.1 {spawn "53_65k_torpedo_spawner" "shooter_001" x no_normal no_position} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 0.1 {spawn "53_65k_torpedo_spawner" "shooter_002" x no_normal no_position} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 0.1 {spawn "53_65k_torpedo_spawner" "shooter_003" x no_normal no_position} } {with_effector}}
			else tagged "shooter04" {with_effector {delay 0.1 {spawn "53_65k_torpedo_spawner" "shooter_004" x no_normal no_position} } {with_effector}}
			else tagged "shooterb00" {with_effector {delay 0.1 {spawn "53_65k_torpedo_spawner" "shooterb_000" x no_normal no_position} } {with_effector}}
			else tagged "shooterb01" {with_effector {delay 0.1 {spawn "53_65k_torpedo_spawner" "shooterb_000" x no_normal no_position} } {with_effector}}
			else tagged "shooterb02" {with_effector {delay 0.1 {spawn "53_65k_torpedo_spawner" "shooterb_000" x no_normal no_position} } {with_effector}}
			}
		   else stuff "vodopad"
			{if tagged "shooter00" {with_effector {delay 0.1 {spawn "vodopad_sub_helper" "shooter_000" x no_normal no_position} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 0.1 {spawn "vodopad_sub_helper" "shooter_001" x no_normal no_position} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 0.1 {spawn "vodopad_sub_helper" "shooter_002" x no_normal no_position} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 0.1 {spawn "vodopad_sub_helper" "shooter_003" x no_normal no_position} } {with_effector}}
			else tagged "shooter04" {with_effector {delay 0.1 {spawn "vodopad_sub_helper" "shooter_004" x no_normal no_position} } {with_effector}}
			else tagged "shooterb00" {with_effector {delay 0.1 {spawn "vodopad_sub_helper" "shooterb_000" x no_normal no_position} } {with_effector}}
			else tagged "shooterb01" {with_effector {delay 0.1 {spawn "vodopad_sub_helper" "shooterb_001" x no_normal no_position} } {with_effector}}
			else tagged "shooterb02" {with_effector {delay 0.1 {spawn "vodopad_sub_helper" "shooterb_002" x no_normal no_position} } {with_effector}}
			}
		   else stuff "3m14 caliber 533torpedo_rus"
			{if tagged "shooter00" {with_effector {delay 0.1 {spawn "caliber_sub_helper" "shooter_000" x no_normal no_position} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 0.1 {spawn "caliber_sub_helper" "shooter_001" x no_normal no_position} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 0.1 {spawn "caliber_sub_helper" "shooter_002" x no_normal no_position} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 0.1 {spawn "caliber_sub_helper" "shooter_003" x no_normal no_position} } {with_effector}}
			else tagged "shooter04" {with_effector {delay 0.1 {spawn "caliber_sub_helper" "shooter_004" x no_normal no_position} } {with_effector}}
			else tagged "shooterb00" {with_effector {delay 0.1 {spawn "caliber_sub_helper" "shooter_000" x no_normal no_position} } {with_effector}}
			else tagged "shooterb01" {with_effector {delay 0.1 {spawn "caliber_sub_helper" "shooter_001" x no_normal no_position} } {with_effector}}
			else tagged "shooterb02" {with_effector {delay 0.1 {spawn "caliber_sub_helper" "shooter_002" x no_normal no_position} } {with_effector}}
			}
		   else stuff "3m54 caliber 533torpedo_rus"
			{if tagged "shooter00" {with_effector {delay 0.1 {spawn "caliber54_sub_helper" "shooter_000" x no_normal no_position} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 0.1 {spawn "caliber54_sub_helper" "shooter_001" x no_normal no_position} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 0.1 {spawn "caliber54_sub_helper" "shooter_002" x no_normal no_position} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 0.1 {spawn "caliber54_sub_helper" "shooter_003" x no_normal no_position} } {with_effector}}
			else tagged "shooter04" {with_effector {delay 0.1 {spawn "caliber54_sub_helper" "shooter_004" x no_normal no_position} } {with_effector}}
			else tagged "shooterb00" {with_effector {delay 0.1 {spawn "caliber54_sub_helper" "shooter_000" x no_normal no_position} } {with_effector}}
			else tagged "shooterb01" {with_effector {delay 0.1 {spawn "caliber54_sub_helper" "shooter_001" x no_normal no_position} } {with_effector}}
			else tagged "shooterb02" {with_effector {delay 0.1 {spawn "caliber54_sub_helper" "shooter_002" x no_normal no_position} } {with_effector}}
			}
		   else stuff "mk48_torpedo"
			{if tagged "shootera00" {with_effector {delay 0.1 {spawn "mk48_torpedo_spawner" "shootera_00" x no_normal no_position} } {with_effector}}
			else tagged "shootera01" {with_effector {delay 0.1 {spawn "mk48_torpedo_spawner" "shootera_01" x no_normal no_position} } {with_effector}}
			else tagged "shooterb00" {with_effector {delay 0.1 {spawn "mk48_torpedo_spawner" "shooterb_00" x no_normal no_position} } {with_effector}}
			else tagged "shooterb01" {with_effector {delay 0.1 {spawn "mk48_torpedo_spawner" "shooterb_01" x no_normal no_position} } {with_effector}}
			}
	       else stuff "ugm-84a"
			{if tagged "shootera00" {with_effector {delay 0.1 {spawn "harpoon_sub_helper" "shootera_00" x no_normal no_position} } {with_effector}}
			else tagged "shootera01" {with_effector {delay 0.1 {spawn "harpoon_sub_helper" "shootera_01" x no_normal no_position} } {with_effector}}
			else tagged "shooterb00" {with_effector {delay 0.1 {spawn "harpoon_sub_helper" "shooterb_00" x no_normal no_position} } {with_effector}}
			else tagged "shooterb01" {with_effector {delay 0.1 {spawn "harpoon_sub_helper" "shooterb_01" x no_normal no_position} } {with_effector}}
			}
		   else stuff "shahed136 base ammo"
			{if tagged "shooter00" {with_effector {delay 0.1 {spawn "shahed136_base" "shooter00" x no_normal no_position {tags add "drone00"}} } {with_effector}}
			else tagged "shooter01" {with_effector {delay 0.1 {spawn "shahed136_base" "shooter01" x no_normal no_position {tags add "drone01"}} } {with_effector}}
			else tagged "shooter02" {with_effector {delay 0.1 {spawn "shahed136_base" "shooter02" x no_normal no_position {tags add "drone02"}} } {with_effector}}
			else tagged "shooter03" {with_effector {delay 0.1 {spawn "shahed136_base" "shooter03" x no_normal no_position {tags add "drone03"}} } {with_effector}}
			else tagged "shooter04" {with_effector {delay 0.1 {spawn "shahed136_base" "shooter04" x no_normal no_position {tags add "drone04"}} } {with_effector}}
			}
		   else stuff "lancet3m fg ammo"
			 {with_effector {tags add "lancet3m_fg"}{with_effector}}
		   else stuff "lancet3m cm ammo"
			 {with_effector {tags add "lancet3m_cm"}{with_effector}}

			else stuff "bullet152_usa rok ammo"
			 {with_effector {delay 0.03 
				{if tagged "no_power" {spawn "shillelagh_carrier" "Foresight1" x {tags add "no_power"}}
				else {spawn "shillelagh_carrier" "Foresight1" x}}}{with_effector}}
			else stuff "bullet152_rus korr ammo"
			 {with_effector {delay 0.03 
				{spawn "krasnopol_test" "Foresight1" x}}{with_effector}}	

;этот блок трогать не нужно
		 else stuff "ammo shell cm supertandem"
		{spawn "cw_cumshassist_spawner_3gen" "missile_point" x}
	      else stuff "ammo shell cm tandem"
		{spawn "cw_cumshassist_spawner_2gen" "missile_point" x}
	      else stuff "ammo shell cm"
		{spawn "cw_cumshassist_spawner_1gen" "missile_point" x}
	      else stuff "ammo shell fg"
		{spawn "cw_fgshassist_spawner" "missile_point" x}
	      else stuff "ammo shell apcr"
		{spawn "cw_apcrshassist_spawner" "missile_point" x}
	      }
	}
}

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
{("CWPS_impulse_proj_eject_slow" missilename(9k14m)  rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(10) imp(17) flight_time(7) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_malutka) bone(tail))}
{("CWPS_impulse_proj" missilename(9k31) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.8) vel(21) imp(37) flight_time(3.7) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(9k37) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.20) vel(23) imp(42) flight_time(3.6) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(9k333) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.4) vel(24) imp(43) flight_time(3.5) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(9k111) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(24) flight_time(4.2) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))}
{("CWPS_impulse_proj" missilename(9k111m) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(24) flight_time(4.6) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))}
{("CWPS_impulse_proj" missilename(9k113) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5.1) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))}
{("CWPS_impulse_proj" missilename(9k113m) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5.1) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))}
{("CWPS_impulse_proj" missilename(9k113m1) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5.1) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))}
{("CWPS_impulse_proj" missilename(9k115-1_cm) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(14) imp(23) flight_time(4.1) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_metis) bone(tracer))}
{("CWPS_impulse_proj" missilename(9k115-2_cm) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(14) imp(23) flight_time(4.4) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_metis) bone(tracer))}
{("CWPS_impulse_proj" missilename(9m38) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.36) vel(28) imp(51) flight_time(6.5) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(9m114f) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(28) imp(51) flight_time(7.2) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(9m114m) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(10) imp(17) flight_time(7) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(9m117) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(19) imp(34) flight_time(4.4) tail(proj_jet_small) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m117m) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(19) imp(34) flight_time(4.4) tail(proj_jet_small) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m117_115) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(19) imp(34) flight_time(3.9) tail(proj_jet_small) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m117cn) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(19) imp(34) flight_time(3.9) tail(proj_jet_small) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m117cn100) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(19) imp(34) flight_time(3.9) tail(proj_jet_small) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m119m) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(20) imp(36) flight_time(4.1) tail(proj_jet_small) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m119m1) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(66) vel(20) imp(36) flight_time(4.1) tail(proj_jet_small) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m120f) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(90) vel(23) imp(41) flight_time(3.9) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(9m120m) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(90) vel(23) imp(41) flight_time(3.9) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(9m133_fg) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(30) flight_time(5.8) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m133_1_cm) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(29) flight_time(5.6) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(9m133_cm) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(29) flight_time(5.1) tail(proj_jet_atgm) eng_time(1))}
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
{("CWPS_impulse_proj" missilename(adats) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(28) imp(55) flight_time(3.2) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(aim-120c7) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(55) flight_time(6.4) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj_airdropped" missilename(aim-120c7_drop) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.4)  vel(28) imp(55) flight_time(6.4) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(aim-120c7_nasams) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(55) flight_time(4.9) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(aim7m) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.60) vel(28) imp(55) flight_time(4.6) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(aim7m_air) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.60) vel(28) imp(55) flight_time(4.6) tail(proj_jet_sam) eng_time(3)) }
{("CWPS_impulse_proj" missilename(aim-9l) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.20) vel(28) imp(51) flight_time(3.7) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(ag300m) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(29) flight_time(8.4) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(agm-65d) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.15) vel(17) imp(30) flight_time(9.9) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(agm-65g) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(17) imp(30) flight_time(9.9) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(agm-84d) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(16) imp(28) flight_time(16.1) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(agm88) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(26) imp(45) flight_time(8.9) tail(proj_jet_atgm) eng_time(3))
	{on "top_attack"
		{delay 0.7 {call "detonate"}}
	}
}
{("CWPS_impulse_proj" missilename(agm-114k) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(agm-114k2) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(agm-114l) rotation(0) rand_move(0) smoke_vulnerable(0.5) decoyprob(0.3) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(agm-114n) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.15) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(agm-114r) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))}
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
{("CWPS_impulse_proj_eject" missilename(akd-10) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(11) imp(19) flight_time(8) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(alarm_missile) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(27) imp(47) flight_time(8.2) tail(proj_jet_atgm) eng_time(3))
	{on "top_attack"
		{delay 0.7 {call "detonate"}}
	}
}
{("CWPS_impulse_proj" missilename(brimstone) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.1) vel(21) imp(38) flight_time(5.8) tail(proj_jet_atgm) eng_time(2))}
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
{("CWPS_impulse_proj" missilename(eryx_rock) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(2.6) tail(proj_jet_atgm) eng_time(1))}

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
{("CWPS_impulse_proj" missilename(hellfire) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.3) vel(21) imp(37) flight_time(4.5) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(hj8e) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(14) imp(24) flight_time(5.4) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))}
{("CWPS_impulse_proj" missilename(hj8h) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(14) imp(24) flight_time(5.4) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))}
{("CWPS_impulse_proj" missilename(hj8f) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(14) imp(24) flight_time(5.4) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))}
{("CWPS_impulse_proj" missilename(hj9_missile) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5.6) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_konkurs) bone(tail))}


{("CWPS_impulse_proj_eject_slow" missilename(hj73c) rotation(1) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(10) imp(17) flight_time(7) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_malutka) bone(tail))}

{("CWPS_impulse_proj" missilename(hq7b) rotation(0) rand_move(1) smoke_vulnerable(0) decoyprob(0.4) vel(28) imp(53) flight_time(4.3) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(hq16a_missile) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.30) vel(28) imp(55) flight_time(6.4) tail(proj_jet_sam) eng_time(3))}
{("CWPS_impulse_proj" missilename(hq16b_missile) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.30) vel(28) imp(55) flight_time(7.3) tail(proj_jet_sam) eng_time(4)) }
{("CWPS_impulse_proj" missilename(hot_rock) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5.1) tail(proj_jet_atgm) eng_time(1))}	
{("CWPS_impulse_proj" missilename(igla_s) rotation(1) rand_move(0) smoke_vulnerable(0) decoyprob(0.25) vel(25) imp(44) flight_time(3.5) tail(proj_jet_sam) eng_time(1.5))}
{("CWPS_impulse_proj" missilename(jav_rock) rotation(0) rand_move(0) smoke_vulnerable(0.5) decoyprob(0.5) vel(12) imp(20) flight_time(5.4) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(javf_rock) rotation(0) rand_move(0) smoke_vulnerable(0.5) decoyprob(0.5) vel(12) imp(20) flight_time(6.2) tail(proj_jet_atgm) eng_time(2))}
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
{("CWPS_impulse_proj" missilename(lahat) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.2) vel(16) imp(28) flight_time(5.4) tail(proj_jet_small) eng_time(1))}
{("CWPS_impulse_proj" missilename(lancet3m_fg) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(5.5) tail(none) eng_time(1))}
{("CWPS_impulse_proj" missilename(lancet3m_cm) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(5.5) tail(none) eng_time(1))}
(define "lancet_impactor"
	{"%impactor" 	
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
	}
)
("lancet_impactor" impactor(lancet3m_fg_impactor))
("lancet_impactor" impactor(lancet3m_cm_impactor))
{("CWPS_impulse_proj" missilename(ld10) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(28) imp(55) flight_time(7.3) tail(proj_jet_atgm) eng_time(2))
	{on "top_attack"
		{delay 0.7 {call "detonate"}}
	}
}
{("CWPS_impulse_proj" missilename(m47dragon_rock) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(13) imp(21) flight_time(4) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(milan_rock) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(13) imp(22) flight_time(4.6) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(milan-er) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.3) vel(13) imp(22) flight_time(5.4) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(mistral_missile) rotation(1) rand_move(0) smoke_vulnerable(0) decoyprob(0.1) vel(28) imp(53) flight_time(2.6) tail(proj_jet_sam) eng_time(1.5))}
{("CWPS_impulse_proj" missilename(mmp_missile) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(11) imp(18) flight_time(7.8) tail(proj_jet_atgm) eng_time(1))}
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
{("CWPS_impulse_proj" missilename(red_arrow_10b) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(13) imp(21) flight_time(8) tail(proj_jet_atgm) eng_time(1))
	{on "launch_procedures"
		{delay 0.1 {with_linked_entity "missile" {ani_play "on_start"}}}
	}
}
{("CWPS_impulse_proj" missilename(red_arrow12_rock) rotation(0) rand_move(0) smoke_vulnerable(0.5) decoyprob(0.5) vel(12) imp(20) flight_time(6.2) tail(proj_jet_atgm) eng_time(2))}
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
{("CWPS_impulse_proj" missilename(shershen_ammo_cm) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(15) imp(25) flight_time(5.8) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(shershen_ammo_fg) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(15) imp(25) flight_time(5.8) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj_airdropped" missilename(slam_er) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0)  vel(14) imp(24) flight_time(19.2) tail(proj_jet_small) eng_time(3))
	{on "link_effects1"
	  {ani_play "top_attack_off" 1}
	}
	{on "top_attack"
		{delay 0.7 {call "detonate"}}
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(spike-lr) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(12) imp(20) flight_time(7.4) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(spike-sr) rotation(0) rand_move(0) smoke_vulnerable(0.5) decoyprob(0.3) vel(10) imp(17) flight_time(6) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(spike-er) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(12) imp(20) flight_time(8) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(spike-er2) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(12) imp(20) flight_time(8) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj_eject" missilename(spike_nlos) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(15) tail(proj_jet_atgm) eng_time(2))}
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
{("CWPS_impulse_proj" missilename(starstreak_ammo) rotation(1) rand_move(0) smoke_vulnerable(0) decoyprob(0.01) vel(28) imp(55) flight_time(2.8) tail(proj_jet_sam) eng_time(0.5))
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
{("CWPS_impulse_proj" missilename(switchblade600) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(10) imp(17) flight_time(5.5) tail(none) eng_time(1))}
{("CWPS_impulse_proj_airdropped" missilename(taurus) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(17) imp(31) flight_time(18.3) tail(proj_jet_main) eng_time(3))
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
{("CWPS_impulse_proj" missilename(tl4_cm) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(11) imp(18) flight_time(8.3) tail(proj_jet_atgm) eng_time(1))}
{("CWPS_impulse_proj" missilename(tow) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.3) vel(15) imp(25) flight_time(5) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_tow) bone(tail))}
{("CWPS_impulse_proj" missilename(tow2d) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(15) imp(25) flight_time(5) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_tow) bone(tail))}
{("CWPS_impulse_proj" missilename(tow2e) rotation(0) rand_move(0) smoke_vulnerable(1) decoyprob(0.1) vel(15) imp(25) flight_time(5) tail(proj_jet_atgm) eng_time(1))("tracer" tracer(tracer_tow) bone(tail))}
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
{("CWPS_impulse_proj_eject" missilename(trigat) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0.10) vel(16) imp(28) flight_time(5.5) tail(proj_jet_atgm) eng_time(2))}
{("CWPS_impulse_proj" missilename(tur_kobra) rotation(1) rand_move(1) smoke_vulnerable(0) decoyprob(0.1) vel(20) imp(36) flight_time(3.8) tail(proj_jet_small) eng_time(1))}
{("CWPS_impulse_proj" missilename(tur_kombat) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(18) imp(32) flight_time(4.5) tail(proj_jet_small) eng_time(1))}
{("CWPS_impulse_proj" missilename(reflex) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(20) imp(36) flight_time(4.1) tail(proj_jet_small) eng_time(1))("speed_normal" coeff(1.14))}
{("CWPS_impulse_proj" missilename(vixr) rotation(1) rand_move(1) smoke_vulnerable(1) decoyprob(0.1) vel(25) imp(45) flight_time(4) tail(proj_jet_atgm) eng_time(2))}
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
	{on "manage_effects1"
		{delay 0.7 {with_linked_entity "missile" {ani_play "on_start"}}}
	}
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
;		{if tagged "cwps_extended_range2" 
		{with_linked_entity "missile" 
			{view stop "proj_jet"}
			{view hide "proj_jet"}
			{view start "proj_jet_main"}
			{tear "piece_missile_booster" bone "part1"{impulse forward 25}}
			{tear "piece_missile_booster" bone "part2"{impulse forward 25}}
		}
;		}
		}
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
		{delay 0.4 {call "detonate"}}
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

		{delay 0.7 
		   {with_linked_entity "missile"
			{view stop "proj_jet"}
			{view hide "proj_jet"}
			{view start "proj_jet_main"}
			 {tear "piece_missile_booster" bone "part1"{impulse forward 10}}
			 {tear "piece_missile_booster" bone "part2"{impulse forward 10}}
		   }
		}
	}
	{on "top_attack" overload
	  {if not tagged "dropped"
		{tags remove "guided"}
		{tags add "dropped"}
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
		{delay 3 
		      {if tagged "cwps_extended_range2"
				{with_linked_entity "missile"
					{view pause "proj_jet"}
					{view stop "proj_jet"}
					{view hide "proj_jet"}
					{tear "piece_missile_booster" bone "starter"{impulse forward 25}}
				}
		      }
;			{if tagged "cwps_extended_range2" {ani_play "top_attack_off" 1} {with_linked_entity "missile" {ani_play "on_start"}}}
;			{delay 15 {ani_play "top_attack_off" 1}}
		}
	}
	{on "top_attack" overload
		{delay 0.7 {call "detonate"}}
	}
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(veter) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(20) imp(36) flight_time(12) tail(proj_jet_sam) eng_time(5))
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
	("speed_normal" coeff(0.85))
	{on "destroyed_by_kaz" overload}
}
{("CWPS_impulse_proj" missilename(vodopad) rotation(0) rand_move(0) smoke_vulnerable(0) decoyprob(0) vel(26) imp(46) flight_time(8) tail(proj_jet_sam) eng_time(4))
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
 