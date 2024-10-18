(define "unitLimits"
	{unitLimits "|engineers=2;|uni_miners=1;|corpsman=10;|single=30;|crewman=4;|snipers=2;|elite_snipers=1;|spotters=6;|saboteurs=4;|recon=4;|airstrike=3;|crate=7;|supp=2;|officer=5"}
)
(define "test_mode"
	{common
		{unitset "%unitset"}
		{chargeFactors "*=%cf"}
		{commandPoints "*=%cp"}
		;{inventory "classic"} ; from commander_inventory.set
		{budgets
			{vehicle
				{mode "with_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}				; round time when money growing
					{restoreBegin 	1}	; points per sec
					{restoreEnd 	1}	; points per sec
					{growTable 	"%growTable"}
					{payback
						{cp	     "0    25   50   75    100"}
						{restore "0.8  0.7  0.6  0.5  0.4"}
					}
				} 
				{buttons "1_common 2_supl  3_vvs_hqcar 3_usaf_hqcar 3_nrf_hqcar 3_cnair_hqcar 4_pvo_hqcar 4_usa_aa_hqcar 4_nato_aa_hqcar 4_cnsam_hqcar 5_artbr_hqcar 5_usart_hqcar 5_abn_hqcar 5_cnart_hqcar 6_mot_hqcar 6_usarmy_hqcar 6_bund_hqcar 6_cnheavy_hqcar 7_specbr_hqcar 7_usmc_hqcar 7_fra_hqcar 7_cnmed_hqcar 8_vdv_hqcar 8_idf_hqcar 8_gb_hqcar 8_iran_hqcar 9_ita_hqcar"}
			}
			{x_special
				{resource 
					{start %sp}
				} 
				{buttons "special"}
			}
		}
	}
)
; with payback
(define "payback_vehicles"
	{common
		{unitset "%unitset"}
		{commandPoints "*=%cp;vvs=%cp;pvo=%cp;artbr=%cp;vdv=%cp;mot=%cp;specbr=%cp;usaf=%cp;usa_aa=%cp;usart=%cp;idf=%cp;usarmy=%cp;usmc=%cp;nrf=%cp;nato_aa=%cp;abn=%cp;bund=%cp;gb=%cp;fra=%cp;ita=%cp;cnair=%cp;cnart=%cp;cnheavy=%cp;cnmed=%cp;cnsam=%cp;cnsco=%cp"} 
		{chargeFactors "*=%cf"}
		{inventory "classic"} ; from commander_inventory.set
		("unitLimits")
		{budgets
			{vehicle
				{mode "with_payback"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	%growTime}				; round time when money growing
					{restoreBegin 	1}	; points per sec
					{restoreEnd 	1}	; points per sec
					{growTable 	"%growTable"}
					{payback
						{cp			"-350		-199		-120		-60		0"}
						{restore	"0.5	0.50	0.3	0.1	0.01"}
					}
				} 
				{buttons "1_common 2_supl  3_vvs_hqcar 3_usaf_hqcar 3_nrf_hqcar 3_cnair_hqcar 4_pvo_hqcar 4_usa_aa_hqcar 4_nato_aa_hqcar 4_cnsam_hqcar 5_artbr_hqcar 5_usart_hqcar 5_abn_hqcar 5_cnart_hqcar 6_mot_hqcar 6_usarmy_hqcar 6_bund_hqcar 6_cnheavy_hqcar 7_specbr_hqcar 7_usmc_hqcar 7_fra_hqcar 7_cnmed_hqcar 8_vdv_hqcar 8_idf_hqcar 8_gb_hqcar 8_iran_hqcar 9_ita_hqcar"}
			}
			{x_special
				{resource 
					{start %sp}
				} 
				{buttons "special"}
			}			
			{z_hqcar
				{mode "standard"}
				{resource
					{start		10000}
				}
				{buttons "hqcar"}
			}
		}
	}
)
{presets
    {"p:payback_100"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "battalion_200"}
		("payback_vehicles" unitset(man_power) cf(1) start(800) finish(4200) sp(250) growTime(1.0) growTable(1) cp(1))
	}
	{"p:payback_test"
		{gameMode "with_payback"}
		{unitMode "vehicles"}
		{specMode "test"}
		("test_mode" unitset(man_power) cf(0) start(10000) finish(25000) sp(15000) growTime(0.01) growTable(0.8 0.9 1.0 1.1 1.3 1.5 1.6) cp(1500))
	}
}
