{"post-biatlon"
	{on contact
		{volumes disable contact}
		{delay 20 {volumes enable contact}}
		{if effector "vehicle"
			{with_effector
				{chassis_work 0}
				{delay 5 {chassis_work 1}}
			}
		}
	}
}
{"tablo"
	(define "show"
		{if tagged "ten_minutes%0" {with_linked_entity "ten_minutes" {tex_morph "ten_minutes%0" 0.01}} {tags remove "ten_minutes%0"}}
		{if tagged "minutes%0" {with_linked_entity "minutes" {tex_morph "minutes%0" 0.01}} {tags remove "minutes%0"}}
		{if tagged "ten_seconds%0" {with_linked_entity "ten_seconds" {tex_morph "ten_seconds%0" 0.01}} {tags remove "ten_seconds%0"}}
		{if tagged "seconds%0" {with_linked_entity "seconds" {tex_morph "seconds%0" 0.01}} {tags remove "seconds%0"}}
	)
	{on "show_time"
		{with_linked_entity "ten_minutes" {tex_morph "void" 0.01}}
		{with_linked_entity "minutes" {tex_morph "void" 0.01}}
		{with_linked_entity "ten_seconds" {tex_morph "void" 0.01}}
		{with_linked_entity "seconds" {tex_morph "void" 0.01}}
		{delay 0.9
		("show" args 0)("show" args 1)("show" args 2)("show" args 3)("show" args 4)
		("show" args 5)("show" args 6)("show" args 7)("show" args 8)("show" args 9)
		}
	}
}