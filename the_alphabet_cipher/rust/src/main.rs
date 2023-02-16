fn main() {
    unimplemented!()
}

const ALPHABET_START: u8 = 'a' as u8;
const ALPHABET_SIZE: u8 = 26;

fn encode(key: &str, msg: &str) -> String {
    String::from_utf8(
        msg.bytes()
            .zip(key.bytes().cycle())
            .map(|(c, k)| {
                ((k - ALPHABET_START) + (c - ALPHABET_START)) % ALPHABET_SIZE + ALPHABET_START
            })
            .collect(),
    )
    .unwrap()
}

fn decode(key: &str, str: &str) -> String {
    String::from_utf8(
        str.bytes()
            .zip(key.bytes().cycle())
            .map(|(c, k)| (ALPHABET_SIZE + c - k) % ALPHABET_SIZE + ALPHABET_START)
            .collect(),
    )
    .unwrap()
}

fn dechiper(msg: &str, str: &str) -> String {
    if msg.len() != str.len() {
        panic!("msg and str must be same size");
    }

    let mut s = String::from_utf8(
        str.bytes()
            .zip(msg.bytes().cycle())
            .map(|(c, m)| (ALPHABET_SIZE + c - m) % ALPHABET_SIZE + ALPHABET_START)
            .collect(),
    )
    .unwrap();

    let mut end = s.len();

    for i in 1..s.len() {
        if s.bytes()
            .skip(i)
            .zip(s.bytes().take(i).cycle())
            .all(|(a, b)| a == b)
        {
            end = i;
            break;
        }
    }

    s.truncate(end);

    s
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_encode_1() {
        let test = String::from("hmkbxebpxpmyllyrxiiqtoltfgzzv");

        let msg = "meetmeontuesdayeveningatseven";

        let result = encode("vigilance".into(), msg);

        assert_eq!(result, test);
    }

    #[test]
    fn test_encode_2() {
        let test = String::from("egsgqwtahuiljgs");

        let msg = "meetmebythetree";

        let result = encode("scones".into(), msg);

        assert_eq!(result, test);
    }

    #[test]
    fn test_decode_1() {
        let test = String::from("meetmeontuesdayeveningatseven");

        let msg = "hmkbxebpxpmyllyrxiiqtoltfgzzv";

        let result = decode("vigilance", msg);

        assert_eq!(result, test);
    }

    #[test]
    fn test_decode_2() {
        let test = String::from("meetmebythetree");

        let msg = "egsgqwtahuiljgs";

        let result = decode("scones", msg);

        assert_eq!(result, test);
    }

    #[test]
    fn test_dechiper_1() {
        let test = String::from("vigilance");

        let msg = "opkyfipmfmwcvqoklyhxywgeecpvhelzg";

        let result = dechiper("thequickbrownfoxjumpsoveralazydog", msg);

        assert_eq!(result, test);
    }

    #[test]
    fn test_dechiper_2() {
        let test = String::from("scones");

        let msg = "hcqxqqtqljmlzhwiivgbsapaiwcenmyu";

        let result = dechiper("packmyboxwithfivedozenliquorjugs", msg);

        assert_eq!(result, test);
    }

    #[test]
    fn test_dechiper_3() {
        let test = String::from("abcabcx");

        let msg = "hfnlphoontutufa";

        let result = dechiper("hellofromrussia", msg);

        assert_eq!(result, test);
    }
}
