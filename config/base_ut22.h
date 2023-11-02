#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>

#define APT 0
#define NUM 1
#define NAV 2
#define SYM 3
#define FUN 4

// &lt {
//     quick_tap_ms = <170>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
    macros {
        macro_sch: macro_sch {
            label = "Macro_sch";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&macro_tap &kp S &kp C &kp H>;
        };
        macro_shifted_sch: macro_shifted_sch {
            label = "Macro_Sch";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <&macro_tap &kp LS(S) &kp C &kp H>;
        };
    };
};


#define COMBO(NAME, BINDINGS, KEYPOS) \
combo_##NAME { \
    timeout-ms = <20>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

//  _______________________  _______________________
// /  0  |  1  |  2  |  3  \/   4 |   5 |   6 |   7 \
// \  8  |  9  | 10  | 11  /\  12 |  13 |  14 |  15 /
//             \ 16  | 17 /  \ 18 |  19 /
//              ----------    ----------

/ {
    combos {
        compatible = "zmk,combos";
/* alphas */
        COMBO(comma, &comsem, 0 1)
        COMBO(f, &kp F, 1 2)
        COMBO(b, &kp B, 2 3)
        COMBO(p, &kp P, 3 4)
        COMBO(z, &kp Z, 4 5)
        COMBO(q, &kp Q, 5 6)
        COMBO(dot, &dotcol, 6 7)

        COMBO(g, &kp G,  9 10)
        COMBO(k, &kp K, 10 11)
        COMBO(j, &kp J, 11 12)
        COMBO(x, &kp X, 12 13)
        COMBO(w, &kp W, 13 14)

/* usually on base layer */
        COMBO(sch, &macro_sch, 0 2)
        COMBO(enter, &kp ENTER, 12 14)
/* parentheticals */
        COMBO(lt, &kp LT, 0 8)
        COMBO(lbrc, &kp LBRC, 1 9)
        COMBO(lbkt, &kp LBKT, 2 10)
        COMBO(lpar, &kp LPAR, 3 11)
        COMBO(gt, &kp GT, 7 15)
        COMBO(rpar, &kp RPAR, 4 12)
        COMBO(rbkt, &kp RBKT, 5 13)
        COMBO(rbrc, &kp RBRC, 6 14)
/* caps */
        COMBO(caps, &caps_word, 11 12)
        COMBO(capslock, &kp CAPSLOCK, 1 6)
/* deletion */
        COMBO(bspc, &kp BSPC, 4 6)
        COMBO(del, &kp DEL, 5 7)
        COMBO(delword, &kp LC(BSPC), 4 7)
    };
};

//  _______________________  _______________________
// /  0  |  1  |  2  |  3  \/   4 |   5 |   6 |   7 \
// \  8  |  9  | 10  | 11  /\  12 |  13 |  14 |  15 /
//             \ 16  | 17 /  \ 18 |  19 /
//              ----------    ----------


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <4 5 6 7 12 13 14 15 16 17 18 19>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 8 9 10 11 16 17 18 19>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            // hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
