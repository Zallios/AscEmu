/*
********************************************************************
Updates for creature_names
********************************************************************
*/
UPDATE `creature_proto` SET `npcflags`= 3 WHERE `entry` = 25590;

INSERT INTO gossip_menu_option
   (`entry`, `option_text`)
VALUES
   (189, 'Go on.'),
   (190, 'Tell me what\'s going on out here, Fizzcrank.');


